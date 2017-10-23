#include <iostream>
using namespace std;

struct lc_exp;

struct lambda_exp { //(lambda(a)b)
  string id;
  lc_exp *body;
};
struct app_exp{ //((a b) (c d))
  lc_exp *rator = NULL;
  lc_exp *rand = NULL;
};

struct var_exp{ //a
  string id;
};

struct lc_exp {
  var_exp* identifier = NULL;
  lambda_exp* lambda = NULL;
  app_exp* app = NULL;
};

bool is_var_exp (lc_exp e) {
  (e.lambda == NULL && e.app == NULL);
};

bool is_lambda_exp (lc_exp e) {
  (e.identifier == NULL && e.app == NULL);
};

bool is_app_exp (lc_exp e) {
  (e.identifier == NULL && e.lambda == NULL);
};

string var_var_exp (lc_exp e) {
  return e.identifier->id;
}
string bound_var_lambda_exp (lc_exp e) {
  return e.lambda->id;
}
lc_exp* body_lambda_exp (lc_exp e) {
  return e.lambda->body;
}
lc_exp* rator_app_exp (lc_exp e) {
  return e.app->rator;
}
lc_exp* rand_app_exp (lc_exp e) {
  return e.app->rand;
}

bool occurs_free (lc_exp e, string search_var){
  if (is_var_exp(e) == true){
    if (var_var_exp(e) == search_var)
      return true;
    else
      return false;
  }
  else if (is_lambda_exp(e) == true){
    if (bound_var_lambda_exp(e) == search_var )
      return false;
    else
      occurs_free(*body_lambda_exp(e), search_var);
  }
  else{
    occurs_free(*rator_app_exp(e), search_var);
    occurs_free(*rand_app_exp(e), search_var);
}
};

int main(){
  // lambda (a) (a b)
  lc_exp statement;
  statement.lambda = new lambda_exp;
  statement.lambda->id = "a";
  
  // a 
  lc_exp var_a;
  var_a.identifier = new var_exp;
  var_a.identifier->id = "a";
  
  // b 
  lc_exp var_b;
  var_b.identifier = new var_exp;
  var_b.identifier->id = "b";
  
  // (a b)
  lc_exp bodyStatement; 
  bodyStatement.app = new app_exp;
  bodyStatement.app->rator = &var_a;
  bodyStatement.app->rand = &var_b;
  
  statement.lambda->body = &bodyStatement;
  lc_exp* output = rand_app_exp(bodyStatement);
  cout << output->identifier->id << endl;
  bool x = occurs_free(bodyStatement, "b");
  cout << x << endl;

}
