#include "Manager.hpp"

//################# PRIMERA ENTREGA ############################//

Manager::Manager() {
    users = vector<User*> ();
    products = vector<Product*> ();
    current_member = -1;
    order_references = vector<unsigned long> ();
    id_reviews = vector<unsigned long> ();
}

Manager::~Manager() {
    for (unsigned long i = 0; i < users.size(); i++) {
        delete users[i];
    }
    for (unsigned long i = 0; i < products.size(); i++) {
        delete products[i];
    }
    users.clear();
    products.clear();
}

const vector<User *> &Manager::getUsers() const {
    return users;
}

const vector<Product *> &Manager::getProducts() const {
    return products;
}

bool Manager::login(const string& email, const string& password) {
    bool flag = false;
    if (current_member == -1) {
        for (unsigned long i = 0; i < users.size(); i++) {
            if ((users[i]->getEmail() == email)&&(users[i]->getPassword() == password)) {
                current_member = i;
                flag = true;
                break;
            }
        }
    }
    return flag;
}

bool Manager::logout() {
    bool flag = false;
    if (isLogged()) {
        current_member = -1;
        flag = true;
    }
    return flag;
}

bool Manager::isLogged() {
    bool flag = false;
    if ((current_member != -1) && (current_member < (int)users.size())) {
        flag = true;
    }
    return flag;
}

User* Manager::getCurrentMember() {
    User* cmember;
    if (isLogged()) {
        cmember = users[current_member];
        return cmember;
    } else {
        return nullptr;
    }
}

bool Manager::addUser(const string &username, const string &email, const string &password) {
    for (User* user: users) {
        if ((user->getEmail() == email)||(user->getUsername() == username)) {
            return false;
        }
    }
    User* new_user = new User(username,email,password);
    users.push_back(new_user);
    return true;
}

bool Manager::addAdministrator(const string &username, const string &email, const string &password, const unsigned long &employee_code) {
    for (User* user: users) {
        if ((user->getEmail() == email)||(user->getUsername() == username)||(user->getEmployeeCode() == employee_code)) {
            return false;
        }
    }
    Administrator* new_admin = new Administrator(username,email,password,employee_code);
    users.push_back(new_admin);
    return true;
}

bool Manager::eraseCurrentMember() {
    bool flag = false;
    if (isLogged()) {
        delete users[current_member];
        users.erase(users.begin() + current_member);
        current_member = -1;
        flag = true;
    }
    return flag;
}

bool Manager::editUsername(const string& new_username) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        for (User* user: users) {
            if (user->getUsername() == new_username) {
                flag = false;
            }
        }
        if (flag) {
           users[current_member]->setUsername(new_username);
           return true;
        } else {
            return false;
        }
    };
}

bool Manager::editEmail(const string& new_email) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        for (User* user: users) {
            if (user->getEmail() == new_email) {
                flag = false;
            }
        }
        if (flag) {
           users[current_member]->setEmail(new_email);
           return true;
        } else {
            return false;
        }
    };
}

bool Manager::editPassword(const string& new_password) {
    if (!isLogged()) {
        return false;
    } else {
        users[current_member]->setPassword(new_password);
        return true;
    }
}

bool Manager::addAddress(const string &address, const string &city, const string &province, const unsigned int &postal_code) {
    bool flag = false;
    int id = users[current_member]->getAddresses().size();
    if (isLogged()) {
        Address* new_address = new Address(address, city, province, postal_code,id);
        users[current_member]->addAddress(new_address);
        flag = true;
    }
    return flag;
}

bool Manager::addCreditCard(const Address *address, const unsigned long &number, const string &cardholder) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        CreditCard* new_creditcard = new CreditCard(id, address, number, cardholder);
        users[current_member]->addPaymentMethod(new_creditcard);
        flag = true;
    }
    return flag;
}

bool Manager::addPaypal(const Address* address, string& email) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        Paypal* new_paypal = new Paypal(id, address, email);
        users[current_member]->addPaymentMethod(new_paypal);
        flag = true;
    }
    return flag;
}

//################# SEGUNDA ENTREGA ############################//

bool Manager::addProduct(const string& name, const string& description, const unsigned long& reference, const float& price) {
    bool flag = true;
    if (!isLogged()) {
        return false;
    } else {
        if (!getCurrentMember()->isAdmin()) {
            return false;
        } else {
            for (Product* product: products) {
                if (product->getReference() == reference) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
            Product* new_product = new Product(name, description, reference, price);
            products.push_back(new_product);
            return true;
            } else {
                return false;
            }
        }
    }
}

vector<PublicUserData*> Manager::showMembers() {
    vector<PublicUserData*> members = vector<PublicUserData*> ();
    if ((isLogged())&&(getCurrentMember()->isAdmin())) {
        for (PublicUserData* public_data: users) {
            members.push_back(public_data);
        }
    }
    return members;
}

bool Manager::makeOrder(const vector<unsigned long> ordered_products, const int& payment_method, const  int& delivery_daddress) {
    bool flag = false, flag_daddres = false, flag_pmethod = false, flag_ref = true;
    float amount = 0.0;
    unsigned long reference;
    Order* new_order;
    srand(time(NULL));
    if (!isLogged()) {
        flag = false;
    } else {
        if ((users[current_member]->getAddresses().size() <= 0) || (users[current_member]->getPaymentMethods().size() <= 0)) {
            flag = false;
        } else {
            for (Address* address : users[current_member]->getAddresses()) {
                if (delivery_daddress == address->getId()) {
                    flag_daddres = true;
                }
            }
            for (PaymentMethod* paymethod : users[current_member]->getPaymentMethods()) {
                if (payment_method == paymethod->getId()) {
                    flag_pmethod = true;
                }
            }
            if (flag_daddres && flag_pmethod) {
                for (unsigned long prod_ref : ordered_products) {
                    for (Product* prod : products) {
                        if (prod_ref == prod->getReference()) {
                            amount += prod->getPrice();
                        }
                    }
                }
                if (users[current_member]->isAdmin()) {
                    amount *= (1 - 0.075);
                }
                do {
                    flag_ref = true;
                    reference = rand();
                    for(unsigned long refs: order_references) {
                        if (reference == refs) {
                            flag_ref = false;
                        }
                    }
                } while (!flag_ref);
                order_references.push_back(reference);
                new_order = new Order(reference, ordered_products, delivery_daddress, payment_method, amount);
                users[current_member]->addOrder(new_order);
                flag = true;
            } else {
                flag = false;
            }
            flag = true;
        }
    }
    return flag;
}

bool Manager::createReview(const unsigned long &reference, const int &rating, const string& text) {
    bool flag = false, flag_id, flag_orderedproduct = false;
    unsigned long id;
    Review* new_review;
    srand(time(NULL));
    if (!isLogged()) {
        flag = false;
    } else {
        do {
            flag_id = true;
            id = rand();
            for (unsigned long ids : id_reviews) {
                if (id == ids) flag_id = false;
            }
        } while(!flag_id);
        for (Order* orders: users[current_member]->getOrders()) {
            for (unsigned long products: orders->getProducts()) {
                if (reference == products) flag_orderedproduct = true;
            }
        }
        if (flag_orderedproduct) {
            PublicUserData* author = users[current_member];
            new_review = new Review(id, rating, text, author);
            for (Product* product: products) {
                if (product->getReference() == reference) {
                    product->addReview(new_review);
                }
            }
            id_reviews.push_back(id);
            users[current_member]->addReview(new_review);
            flag = true;
        } else {
            flag = false;
        }
    }
    return flag;
}

vector<Review*> Manager::getReviewsByRating(const unsigned long &reference, const int &rating) {
    vector<Review*> filtered_reviews;
    for (Product* product: products){
        if (reference == product->getReference()){
            vector <Review*> rev = product->getReviews();
            for (Review* reviews: rev ){
                if (rating == reviews->getRating())
                    filtered_reviews.push_back(reviews);
            }
        }
    }
    return filtered_reviews;
}

bool Manager::upvoteReview(const unsigned long& id) {
    bool flag = false, valid_id = false;
    Review* selected_review = nullptr;
    for (Product* product: products) {
        for (Review* rev: product->getReviews()) {
            if (rev->getId() == id) {
                selected_review = rev;
                valid_id = true;
                break;
            }
        }
        if (valid_id) {
            break;
        }
    }
    if (!valid_id) {
        return false;
    } else {
        if (!isLogged()) {
            flag = false;
        } else {
            //Author of the review and voter are different users
            if (users[current_member]->getUserReviews().size() > 0) {
                for (Review* reviews_madebyuser: users[current_member]->getUserReviews()) {
                    if (reviews_madebyuser->getId() == id) {
                        return false;
                    }
                }
            }
            //Reviewer can only vote review once
            for(PublicUserData* users_alreadyvoted: selected_review->getUserVotedReview()) {
                if (users_alreadyvoted->getUsername() == users[current_member]->getUsername()) {
                    return false;
                }
            }
            selected_review->incrementVotes();
            selected_review->getAuthor()->increaseReputation();
            selected_review->setUserVotedReview(users[current_member]);
            flag = true;
        }
        return flag;
    }
}

bool Manager::downvoteReview(const unsigned long& id) {
    bool flag = false, valid_id = false;
    Review* selected_review = nullptr;
    for (Product* product: products) {
        for (Review* rev: product->getReviews()) {
            if (rev->getId() == id) {
                selected_review = rev;
                valid_id = true;
                break;
            }
        }
        if (valid_id) {
            break;
        }
    }
    if (!valid_id) {
        return false;
    } else {
        if (!isLogged()) {
            flag = false;
        } else {
            //Author of the review and voter are different users
            if (users[current_member]->getUserReviews().size() > 0) {
                for (Review* reviews_madebyuser: users[current_member]->getUserReviews()) {
                    if (reviews_madebyuser->getId() == id) {
                        return false;
                    }
                }
            }
            //Reviewer can only vote review once
            for(PublicUserData* users_alreadyvoted: selected_review->getUserVotedReview()) {
                if (users_alreadyvoted->getUsername() == users[current_member]->getUsername()) {
                    return false;
                }
            }
            selected_review->decremVotes();
            selected_review->getAuthor()->decreaseReputation();
            selected_review->setUserVotedReview(users[current_member]);
            flag = true;
        }
        return flag;
    }
}

bool Manager::modifyReviewRating(const unsigned long &id, const int &new_rating) {
    bool flag = false;
    Review* new_review;
    unsigned long reference;
    if (!isLogged()) {
        return flag;
    } else {
        for (Product* product: products){
            vector <Review*> rev = product->getReviews();
            for (Review* reviews: rev){
                if(id == reviews->getId() ){
                    reference = product->getReference();
                    if (reviews->getAuthor()->getUsername() == users[current_member]->getUsername()){
                        new_review = new Review(id, new_rating, reviews->getText(), getCurrentMember());
                        for (Product* product: products) {
                            if (product->getReference() == reference) {
                                product->addReview(new_review);
                            }
                        }
                        id_reviews.push_back(id);
                        flag = true;
                       }
                    }
                }
            }
        }
        return flag;
}

bool Manager::modifyReviewText(const unsigned long &id, const string& new_text){
    bool flag = false;
    Review* new_review;
    unsigned long reference;
    if (!isLogged()) {
        return flag;
    } else {
        for (Product* product: products){
            vector <Review*> rev = product->getReviews();
            for (Review* reviews: rev){
                if(id == reviews->getId() ){
                    reference = product->getReference();
                    if (reviews->getAuthor()->getUsername() == users[current_member]->getUsername()){
                        new_review = new Review(id, reviews->getRating(), new_text, getCurrentMember());
                        for (Product* product: products) {
                            if (product->getReference() == reference) {
                                product->addReview(new_review);
                            }
                        }
                        id_reviews.push_back(id);
                        flag = true;
                       }
                    }
                }
            }
        }
        return flag;
}

bool Manager::deleteReview(const unsigned long &id) {
    bool flag = false;
    if (!isLogged()) {
        return flag;
    } else {
        for (Product* product: products){
            vector <Review*> rev = product->getReviews();
            for (Review* reviews: rev){
                if(id == reviews->getId() ){
                    if (!getCurrentMember()->isAdmin()) {
                        reviews->~Review();
                        return flag;
                    }else{
                        if (reviews->getAuthor()->getUsername() == users[current_member]->getUsername()){
                            reviews->~Review();
                            flag = true;
                            return flag;
                         }else{
                            return flag;
                        }
                    }
                }
            }
        }
    }
    return flag;
}


//################# TERCERA ENTREGA ############################//

void Manager::saveToFile(string& route) {}

void loadFromFile(string route) {}

