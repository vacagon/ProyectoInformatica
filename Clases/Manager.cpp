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
    for (User* every_user: users) {
        for (Order* every_order: every_user->getOrders()) {
            delete every_order;
        }
        for (PaymentMethod* every_paymentmethod: every_user->getPaymentMethods()) {
            delete every_paymentmethod;
        }
        for (Address* every_address: every_user->getAddresses()) {
            delete every_address;
        }
        every_user->getOrders().clear();
        every_user->getPaymentMethods().clear();
        every_user->getAddresses().clear();
    }
    for (Product* every_product: products) {
        for (Review* every_review: every_product->getReviews()) {
            delete every_review;
        }
        every_product->getReviews().clear();
    }
    for (unsigned long i = 0; i < users.size(); i++) {
        delete users[i];
    }
    for (unsigned long i = 0; i < products.size(); i++) {
        delete products[i];
    }
    users.clear();
    products.clear();
    order_references.clear();
    id_reviews.clear();
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
        for (Order* order: users[current_member]->getOrders()) {
            delete order;
        }
        users[current_member]->getOrders().clear();
        for (PaymentMethod* payment_methods: users[current_member]->getPaymentMethods()) {
            delete payment_methods;
        }
        users[current_member]->getPaymentMethods().clear();
        for (Address* addresses: users[current_member]->getAddresses()) {
            delete addresses;
        }
        users[current_member]->getAddresses().clear();
        for (Review* reviews: users[current_member]->getUserReviews()) {
            delete reviews;
        }
        users[current_member]->getUserReviews().clear();
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

bool Manager::addCreditCard(Address *address, const unsigned long &number, const string &cardholder) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        CreditCard* new_creditcard = new CreditCard(id, address, number, cardholder);
        users[current_member]->addPaymentMethod(new_creditcard);
        users[current_member]->addCreditCard(new_creditcard);
        flag = true;
    }
    return flag;
}

bool Manager::addPaypal(Address* address, string& email) {
    bool flag = false;
    int id = users[current_member]->getPaymentMethods().size();
    if (isLogged()) {
        Paypal* new_paypal = new Paypal(id, address, email);
        users[current_member]->addPaymentMethod(new_paypal);
        users[current_member]->addPaypal(new_paypal);
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
    bool flag = false, valid_id = false;
    Review* selected_review = nullptr;
    if (!isLogged()) {
        flag = false;
    } else {
        for (Review* rev: users[current_member]->getUserReviews()) {
            if (rev->getId() == id) {
                selected_review = rev;
                valid_id = true;
                break;
            }
        }
        if (!valid_id) {
            flag = false;
        } else {
            selected_review->setRating(new_rating);
            flag = true;
        }
    }
    return flag;
}

bool Manager::modifyReviewText(const unsigned long &id, const string& new_text){
    bool flag = false, valid_id = false;
    Review* selected_review = nullptr;
    if (!isLogged()) {
        flag = false;
    } else {
        for (Review* rev: users[current_member]->getUserReviews()) {
            if (rev->getId() == id) {
                selected_review = rev;
                valid_id = true;
                break;
            }
        }
        if (!valid_id) {
            flag = false;
        } else {
            selected_review->setText(new_text);
            flag = true;
        }
    }
    return flag;
}

bool Manager::deleteReview(const unsigned long &id) {
    bool flag = false, valid_id = false;
    if (!isLogged()) {
        flag = false;
    } else {
        for (Product* every_product: products) {
            for (Review* every_review: every_product->getReviews()) {
                if (every_review->getId() == id) {
                    if (users[current_member]->isAdmin()) {
                        every_product->deleteReview(every_review);
                        for (int i = 0; i < users.size(); i++) {
                            if (users[i]->getUsername() == every_review->getAuthor()->getUsername()) {
                                users[i]->deleteReview(every_review);
                            }
                        }
                        valid_id = true;
                        break;
                    } else {
                        if (every_review->getAuthor()->getUsername() == users[current_member]->getUsername()) {
                            every_product->deleteReview(every_review);
                            users[current_member]->deleteReview(every_review);
                            valid_id = true;
                            break;
                        }
                    }
                }
            }
            if (valid_id) {
                break;
            }
        }
        if (!valid_id) {
            flag = false;
        } else {
            flag = true;
        }
    }
    return flag;
}

//################# TERCERA ENTREGA ############################//

void Manager::saveToFile(const string route) {
    ofstream ofile(route, ios::out);
    for (User* every_user: users) {
        ofile << "User:" << endl
              << every_user->getUsername() << endl
              << every_user->getEmail() << endl
              << every_user->getPassword() << endl
              << every_user->getReputation() << endl;
        if (every_user->isAdmin()) {
            ofile << every_user->getEmployeeCode() << endl;
        } else {
            ofile << "-1" << endl;
        }
        if (every_user->getAddresses().size() > 0) {
            for (Address* every_address: every_user->getAddresses()) {
                ofile << "Address:" << endl
                      << every_address->getId() << endl
                      << every_address->getAddress() << endl
                      << every_address->getCity() << endl
                      << every_address->getProvince() << endl
                      << every_address->getPostalCode() << endl;
            }
        }
        if (every_user->getCreditCards().size() > 0) {
            for (CreditCard* every_creditcard: every_user->getCreditCards()) {
               ofile << "CreditCard:" << endl
                     << every_creditcard->getId() << endl
                     << every_creditcard->getBillingAddress()->getId() << endl
                     << every_creditcard->getNumber() << endl
                     << every_creditcard->getCardholder() << endl;
            }
        }
        if (every_user->getPaypals().size() > 0) {
            for (Paypal* every_paypal: every_user->getPaypals()) {
                ofile << "Paypal:" << endl
                      << every_paypal->getId() << endl
                      << every_paypal->getBillingAddress()->getId() << endl
                      << every_paypal->getEmail() << endl;
            }
        }
        if (every_user->getOrders().size() > 0) {
            for (Order* every_order: every_user->getOrders()) {
                ofile << "Order:" << endl
                      << every_order->getReference() << endl;
                for (unsigned long every_product: every_order->getProducts()) {
                    ofile << "order_product:" << endl
                          << every_product << endl;
                }
                ofile << every_order->getDate() << endl
                      << every_order->getDeliveryAddress() << endl
                      << every_order->getPaymentMethod() << endl
                      << every_order->getTotal() << endl;
            }
        }
    }
    for (Product* every_product: products) {
        ofile << "Product:" << endl
              << every_product->getName() << endl
              << every_product->getDescription() << endl
              << every_product->getReference() << endl
              << every_product->getPrice() << endl;
        if (every_product->getReviews().size() > 0) {
            for (Review* every_review: every_product->getReviews()) {
                ofile << "Review:" << endl
                      << every_review->getId() << endl
                      << every_review->getDate() << endl
                      << every_review->getRating() << endl
                      << every_review->getText() << endl
                      << every_review->getVotes() << endl
                      << every_review->getAuthor()->getUsername() << endl;
            }
        }
    }
    ofile.close();
}

void Manager::loadFromFile(const string route) {
    ifstream ifile(route, ios::in);
    ifile.seekg(0, ios::beg);
    string titulo, titulo2, titulo3;
    getline(ifile, titulo, '\n');
    while (titulo.find("User:") != string::npos) {
        logout();
        string username, email, password, sreputation, check;
        int reputation;
        bool isAdmin = false;
        unsigned long employee_code;
        getline(ifile, username, '\n');
        getline(ifile, email, '\n');
        getline(ifile, password, '\n');
        getline(ifile, sreputation, '\n');
        reputation = stoi(sreputation);
        getline(ifile, check, '\n');
        if (check != "-1") {
            employee_code = stoul(check);
            isAdmin = true;
            Administrator* new_admin = new Administrator(username, email, password, employee_code);
            users.push_back(new_admin);
        } else {
            isAdmin = false;
            User* new_user = new User(username, email, password);
            users.push_back(new_user);
        }
        login(email, password);
        getline(ifile, titulo2, '\n');
        while (titulo2 == "Address:") {
            int id;
            unsigned int postal_code;
            string address, city, province, sid, spostal_code;
            getline(ifile, sid, '\n');
            id = stoi(sid);
            getline(ifile, address, '\n');
            getline(ifile, city, '\n');
            getline(ifile, province, '\n');
            getline(ifile, spostal_code, '\n');
            postal_code = stoi(spostal_code);
            Address* new_address = new Address(address, city, province, postal_code, id);
            getCurrentMember()->addAddress(new_address);
            getline(ifile, titulo2, '\n');
        }
        while ((titulo2 == "CreditCard:")||(titulo2 == "Paypal:")) {
            if (titulo2 == "CreditCard:") {
                int id, billing_address;
                string cardholder, sid, sbilling_address, snumber;
                Address* billing_add;
                unsigned long number;
                getline(ifile, sid, '\n');
                id = stoi(sid);
                getline(ifile, sbilling_address, '\n');
                billing_address = stoi(sbilling_address);
                for (Address* address: getCurrentMember()->getAddresses()) {
                    if (id == address->getId()) {
                        billing_add = address;
                    }
                }
                getline(ifile, snumber, '\n');
                number = stoul(snumber);
                getline(ifile, cardholder, '\n');
                CreditCard* new_creditcard = new CreditCard(id, billing_add, number, cardholder);
                getCurrentMember()->addCreditCard(new_creditcard);
                getCurrentMember()->addPaymentMethod(new_creditcard);
            }
            if (titulo2 == "Paypal:") {
                int id, billing_address;
                string email, sid, sbilling_address;
                Address* billing_add;
                getline(ifile, sid, '\n');
                id = stoi(sid);
                getline(ifile, sbilling_address, '\n');
                billing_address = stoi(sbilling_address);
                for (Address* address: getCurrentMember()->getAddresses()) {
                    if (id == address->getId()) {
                        billing_add = address;
                    }
                }
                getline(ifile, email, '\n');
                Paypal* new_paypal = new Paypal(id, billing_add, email);
                getCurrentMember()->addPaypal(new_paypal);
                getCurrentMember()->addPaymentMethod(new_paypal);
            }
            getline(ifile, titulo2, '\n');
        }
        while (titulo2 == "Order:") {
            unsigned long reference_order;
            vector<unsigned long> products;
            string product, reference, spayment_method, sfloat, reference_product, saddress;
            int payment_method, delivery_address;
            float total;
            time_t date;
            getline(ifile, reference, '\n');
            reference_order = stoul(reference);
            getline(ifile, titulo3, '\n');
            while (titulo3 == "order_product:") {
                getline(ifile, reference_product, '\n');
                products.push_back(stoul(reference_product));
                getline(ifile, titulo3, '\n');
            }
            date = stoul(titulo3);
            getline(ifile, saddress, '\n');
            delivery_address = stoi(saddress);
            getline(ifile, spayment_method, '\n');
            payment_method = stoi(spayment_method);
            getline(ifile, sfloat, '\n');
            total = stof(sfloat);
            Order* new_order = new Order(reference_order, products, delivery_address, payment_method, total);
            new_order->setDate(date);
            getCurrentMember()->addOrder(new_order);
            getline(ifile, titulo2, '\n');
        }
     titulo = titulo2;
     logout();
    }
    while ((titulo == "Product:")&&(ifile)) {
        string name, description, sreference, sprice;
        unsigned long reference;
        float price;
        vector<Review*> reviews = vector<Review*> ();
        getline(ifile, name, '\n');
        getline(ifile, description, '\n');
        getline(ifile, sreference, '\n');
        reference = stoul(sreference);
        getline(ifile, sprice, '\n');
        price = stof(sprice);
        getline(ifile, titulo2, '\n');
        while (titulo2 == "Review:") {
            unsigned long id_review;
            string sid_review, sdate, srating, text, svotes, username;
            time_t date;
            int rating, votes;
            PublicUserData* author;
            getline(ifile, sid_review, '\n');
            id_review = stoul(sid_review);
            getline(ifile, sdate, '\n');
            date = stoul(sdate);
            getline(ifile, srating, '\n');
            rating = stoi(srating);
            getline(ifile, text, '\n');
            getline(ifile, svotes, '\n');
            votes = stoi(svotes);
            getline(ifile, username, '\n');
            getline(ifile, titulo2, '\n');
            for (User* user: users) {
                if (user->getUsername() == username) {
                    author = user;
                }
            }
            Review* new_review = new Review(id_review, rating, text, author);
            reviews.push_back(new_review);
        }
        Product* new_product = new Product(name, description, reference, price);
        if (reviews.size() > 0) {
            for (Review* product_reviews: reviews) {
                new_product->addReview(product_reviews);
            }
        }
        products.push_back(new_product);
        titulo = titulo2;
    }
    ifile.close();
}

//################# MÉTODOS PROPIOS ############################//

vector<unsigned long> Manager::getIdReviews() const {
    return id_reviews;
}
