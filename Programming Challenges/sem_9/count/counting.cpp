# include <fstream>
#include <ostream>
# include <stdlib.h>
# include <string.h>
const int BASE = 10000;

class BigNum{
 protected:
  int *x;               //this array holds the BigNum
  char positive;        //sign flag
  long exp;             //array index of most significant digit

 public:
  BigNum(char *s);                        //construct from string
  BigNum(long k=0,long new_sz=0);         //construct from long
  BigNum(const BigNum &b,long new_sz=0);  //copy constructor
  ~BigNum(){delete[] x;}                  //destructor

  friend ostream& operator<<(ostream & os, BigNum &b);  //for printing

  BigNum & operator=(const BigNum &b);  //assignment
  BigNum & operator=(long k);           //assignment from long
  BigNum operator+(const BigNum & b);   //addition

  BigNum operator-(const BigNum &b);    //subtraction
  BigNum operator/(const BigNum &den);  //divide bignums
  BigNum operator/(long denom);         //divide bignum by long
  BigNum operator*(const BigNum & b);   //bignum multiplication
  BigNum operator^(const long n);       //exponentiation

  //easy routines; these are easily implemented and are not
  //included here to save space. The complete listings may be
  //obtained from my web page.
  BigNum operator-();                   //unary minus
  BigNum operator+(const long k);       //addition with long
  BigNum operator-(const long k);       //Bignum - long
  BigNum operator*(long k);             //multiply bignum * long
  BigNum operator%(const BigNum &denom);//remainder of division
  long operator%(const long denom);     //rem. Of bignum / long
  char operator<=(const BigNum &b);
  char operator>(const BigNum &b);
  char operator>=(const BigNum &b);
  char operator==(const BigNum &b);
  char operator<(const BigNum &b);
  char operator<=(const long k);
  char operator>(const long k);
  char operator>=(const long k);
  char operator==(const long k);
  char operator<(const long k);
  char is_zero();               //returns 1 if value of BigNum is zero
  void asl(const long n);       //arithmetic shift left; equivalent to
                                // multiplying by base n times
  void asr(const long n);       //arithmetic shift right
  long BigNum2Long();           //convert a bignum to a long
                                //if possible
  BigNum abs(const BigNum &b);  //absolute value
  void random(const int size);  //makes a random bignum of size digits
};

//add 2 BigNums
BigNum  BigNum::operator+(const BigNum &b){
 if (positive){
  if (b.positive){
     if (exp < b.exp) return (b + *this);
     else{
        BigNum a;
        a.exp = exp + 1;
        delete[] a.x; a.x = new int[a.exp+1];
        a.positive = 1; a.x[a.exp]=0;
        long carry=0; long temp;
        for (int i=0;i<=b.exp;i++){
          temp =
            long(x[i])+long(b.x[i])+carry;
          a.x[i] = temp % BASE;
          carry = temp/BASE;
        }
        for(i=b.exp+1;i<=exp;i++){
          temp = x[i] + carry;
          a.x[i] = temp % BASE;
          carry = temp/BASE;
        }
        if (!a.x[a.exp]) a.exp--;
        return a;
     }
  //a pos & b neg
  }else return (*this - (-b));
 }else{
      if (b.positive)
        return (b - (-*this)); //a neg
      else
        //a neg & b neg
        return (- (-*this) + (-b));
 }
}

//subtract a BigNum from another BigNum
BigNum BigNum::operator-(const BigNum &b){
  if (positive){
     if (b.positive){
      if (*this<b) return(-(b-*this));
      BigNum a; a.exp = exp;
      delete[] a.x; a.x = NULL;
      a.x = new int[a.exp+1];
      a.positive = 1; a.x[a.exp]=0;
      for (int i=0;i<=exp;i++) a.x[i]=x[i];
      for(i=0;i<=b.exp;i++){
         long temp = a.x[i] - b.x[i];
         if (temp < 0){
           a.x[i+1]-=1;
           temp+=BASE;
         }
         a.x[i] = temp;
      }
      i = b.exp+1;
      while(a.x[i]<0){
        a.x[i++]+=BASE;a.x[i]-=1;
      }
      while(!a.x[a.exp] && a.exp) a.exp--;
      return a;
     }else
       //a pos & b neg
       return (*this + (-b));
  }else{  //a negative
     if (b.positive)return (-(b + (-*this)));
     else return(b-*this);
  }
}
//End of File


//multiply two bignums
BigNum BigNum::operator*(const BigNum & b){
  BigNum product;
  product.exp = this->exp + b.exp + 1;
  delete[] product.x;  product.x = new int[product.exp+1];
  product.positive = (this->positive==b.positive);
  for (int j = 0; j<=product.exp; j++) product.x[j] = 0;

  long carry;
  for(j=0;j<=b.exp;j++){
     carry = 0;
     for(int i=0;i<=this->exp;i++){
        long t = this->x[i];
        t = t * long(b.x[j]) + product.x[i+j] + carry;
        product.x[i+j] = t % BASE; carry = t/BASE;
     }
     product.x[i+j] = carry;
  }
  while(!product.x[product.exp] && product.exp) product.exp--;
  return product;
}

BigNum BigNum::operator/(long denom){
 BigNum a;
  if (abs(*this)<abs(denom)) return a;
  a.positive =
    ((denom<0 && !this->positive) ||
    (denom>0 && this->positive));
  if (denom <0) denom = -denom;
  long r = 0;
  if (denom){
     a = *this;
     for(int i=this->exp;i>=0;i--){
      long temp = long(this->x[i]) + r*BASE;
      a.x[i] = temp/denom; r = temp % denom;
     }
     while(!a.x[a.exp] && a.exp) a.exp--;
    }
    else cerr << "divide by zero error";
    return a;
}
//End of File

//divide a bignum by another bignum
BigNum BigNum::operator/(const BigNum &denom){
     BigNum q;
     q.positive = (this->positive == denom.positive);
     if (abs(*this)<abs(denom)) return q;

     if (denom.exp <= 0){ //denom is a long;
                          //send it to the easy routine
         long x = denom.x[0];
         return (*this/x);
     }else{
         delete[] q.x;
         q.exp = this->exp - denom.exp;
         q.x = new int[q.exp+1];
         long qhat;  int qpos = q.exp;
         long d = BASE/(denom.x[denom.exp]+1); //d is a normalizer

         BigNum u(*this); //make a copy of the numerator
         BigNum v(denom); //make a copy of the denominator
         long start = u.exp+1;
         u = u*d;  v = v*d;
         if (u.exp<start){ u.exp = start;  u.x[start]=0;}

         for(;;){
          if (abs(u)<abs(v)){ //when u<v we can't divide anymore
            u = u/d;          //unnormalize u to get remainder
            return q;
          }
          int i = 0; long stop;
          while(u.x[start+i]==v.x[v.exp+i] && v.exp+i)i--;
          if (u.x[start+i] < v.x[v.exp+i])stop = start - v.exp -1;
          else stop = start - v.exp;

          qhat = long(u.x[start]);         //make a guess at qhat
          qhat = qhat*BASE + u.x[start-1];qhat/=v.x[v.exp];
          if (qhat > BASE-1) qhat = BASE-1;

          long temp;
          //fast check to see if qhat is too big
          if (start-1) temp = u.x[start-2]; else temp = 0;
          while (long(v.x[v.exp-1])*qhat>(long(u.x[start])*BASE + 
                      u.x[start-1]-qhat*long(v.x[v.exp]))*BASE +
                      temp)
          qhat--;

          BigNum work(v*qhat,u.exp);

          //qhat still too big??
          while(start-stop < work.exp){--qhat;  work = work - v;}

          long borrow = 0;                 //subtract work from u
          work.x[work.exp+1] = 0;
          for(i=stop;i<=start; i++){
             temp = long(u.x[i]) - long(work.x[i-stop]) + borrow;
             if (temp < 0){borrow = -1;temp+=BASE;}
             else borrow = 0;
             u.x[i] = temp;
          }

          v.x[v.exp+1] = 0;
          while (borrow < 0 && qhat){//oops qhat was still too big
                                     //add back
             qhat--;
             long carry = 0;
             for(i=stop;i<=start; i++){
                temp = u.x[i] + v.x[i-stop] + carry;
                carry = temp/BASE;
                u.x[i] = temp % BASE;
             }
             borrow += carry;
          }

          q.x[qpos--] = qhat;
          start = --u.exp;          //work on next digit of u
        }
     }
}
//End of File

//raise bignum to the nth power
BigNum BigNum::operator^(const long n){
  if (n>0){
     if (n==2) return ((*this) * (*this));
     if (n%2==0) return (((*this)^(n/2))^2);
     else return (*this * ((*this)^(n-1)));
  }else{
     if (!n) return BigNum(1); else return BigNum(long(0));
  }
}

//construct BigNum from char string; only works if BASE == 10000
BigNum::BigNum(char *s){
  int k,ind,l = strlen(s);
  exp = l/4;
  if (l%4==0) exp--;
  x = new int[exp+1];
  char *d, *s2;
  d = new char[l];  s2 = new char[l];
  strcpy(s2,s);  //make copy of s so that we don't trash original
  l--; k = l - 3; if (k<0) k = 0; ind = l-k+1;
  for (int i = 0;i<=exp;i++){
     d = s2+k;
     d[ind] = '\0'; x[i] = atoi(d)
     l -=4;  k-=4; if (k<0) k = 0;
     ind = l-k+1;
  }
  delete[] d;   delete[] s2;
}

//construct BigNum from long; new_sz param allows one to create
//a larger than necessary array of ints
BigNum::BigNum(long k,long new_sz){
  long k2 = k/BASE; int sz = 1;
  while(k2){sz++; k2 /= BASE;}    //determine size of int array
  if (sz >= new_sz) x = new int[sz]; else x = new int[new_sz];
  if (k>=0) positive = 1;
  else{ k = -k; positive = 0;}
  long carry = k; exp = -1;
  while (carry){ x[++exp] = carry % BASE; carry /= BASE;}
}

//copy constructor
BigNum::BigNum(const BigNum &b,long new_sz){
  if (b.exp+1 >= new_sz) x = new int[b.exp+1];
  else x = new int[new_sz];
  positive = b.positive; exp = b.exp;
  for (int i=0;i<=exp;i++)x[i] = b.x[i];
}

//assign a long to a bignum
BigNum & BigNum::operator=(long k){
  delete[] x;
  long k2 = k/BASE; int sz = 1;
  while(k2){sz++; k2 /= BASE;}
  x = new int[sz];

  if (k>=0)positive = 1;
  else{ k = -k; positive = 0;}

  long carry = k;
  exp = -1;
  while (carry){x[++exp] = carry % BASE; carry /= BASE;}
  return *this;
}

//assign a bignum to a bignum
BigNum & BigNum::operator=(const BigNum &b){
  delete[] x;
  x = new int[b.exp+1];
  exp = b.exp; positive = b.positive;
  for (int i = 0;i<=exp; i++) x[i] = b.x[i];
  return *this;
}

//allow easy printing of bignums
ostream& operator<<(ostream & os, BigNum &b){
  if (!b.positive){ os << "-";}
  int j = 0;
  for (int i = b.exp; i >=0; i--){
      if (++j % 15 == 0) os << "\n";
      os.fill('0');os.width(4);os <<  b.x[i];
  }
  return os;
}
//End of File
