// C++ cheat sheet


//===== Do While =========
//========================

do{
    cout<<i;
    i++;
	}while(i<2);

//========================
//========================



//===== Random Number ====
//========================

#include <cstdlib>
int r = rand();

// in a range for 0 to x
int x = 15;
rand() % x;
rand() % 15;

// in a range from 10 to 25 === sets offset from 0 to 10
( rand() % 15 ) + 10;

//=========================
//=========================



// ===== Arrays ================================================================
//===============================================================================

//----- Initialization -----------------
int a[5]; // No Initialization
    for(int i = 0; i< 5 ; i++){
        cout<<a[i]<<endl;}
// Garbage Output
5072272
0
7
0
0

int a[5] = {}; // Initializes all to 0
int a[5] = {0}; // Initializes first element to 0
int a[5] = {1,2}; // Initializes first element to 1 and second to 2
//--------------------------------------


// ----- Passing Array to function -----
// In C++ entire array cannot be passed - only its address is passed
// leave the first [] empty in the parameters of function
// -------------------------------------
void funcT(int a[]){}
int a[6] = {};
funcT(a);

void funcT(int a[][4]){}
int a[10][4] = {};
fucnT(a);
//Any changes made in function are made to the arrya itself not its copy :D
//--------------------------------------


//================================================================================
//================================================================================



//====== Char Array ==============================================================
//================================================================================

char carr[4] = {'A','B','C','\0'}; // len=4 , as '\0 is inluded'
//OR
char carr[] = {'A','B','C','\0'}; // Need to have '\0' to know where char array ends
cout<<carr;
>> ABC
//OR
char carr[] = "Vatsal"; // Automatically appends a '\0' at end.
cout<<carr;
>> Vatsal

//----- Input with spaces --------------
char carr[20];
cin.getline(carr,20);
for(int i=0; i<20 ; i++){
    cout<<carr[i];
}
cout << endl << carr;

//--------------------------------------
//================================================================================
//================================================================================



//========= Pointers =============================================================
//================================================================================

int x = 100;
cout << &x; // prints the memory address of variable x
			// the memory location gets assigned atg runtime the location is differnt
>>0x24fe4c

//-------------------
int x = 100;
int *p = &x; // p is pointer to address of x
cout << &x << endl;
cout<< p << endl;;
cout << *p << endl; // * is used to de-refference and get the value pointed by the address

>> 0x24fe44
>> 0x24fe44
>> 100
//-------------------    

//------ Pointer to same value-------
int *q = p;
cout << q << endl;
cout << *q << endl;

>> 0x24fe44
>> 100

//OR

int *q;
q = p;
cout << q << endl;
cout << *q << endl;

>> 0x24fe44
>> 100
//----------------------------------

//------ Pointer to Array -------------
// Array variable points to the array's address itself
int array[] = {1,2,3,4,5,6};
    cout << *array << endl;
    cout << *array + 1 << endl;
>> 1
>> 2

int *p;
p = array;
*(p+1) = 200;
*(p+2) = 300;

>>1       200     300     4       5       6

//----------------------------------

//----- Pointer to fuctions -------
void funcT(int x, int y){
    cout << (x + y);
    }
void pass(int a, int b, void(*f)(int, int)){
    return f(a,b);
    }
 pass(2,3, funcT);// pass the function;
 >> 5

 //OR

 void (*func)(int, int) = funcT;
 pass(2,3, func);// pass a pointer to the function
 >>5 
//---------------------------------- 

//----- Pointer to a Pointer -------
 int a = 10;
int *b = &a;
int **c = &b;

cout << a << endl;
>> 10
cout << &a << endl;
>> 0x24fe4c         // address of a
cout << b << endl;
>> 0x24fe4c         // b stores address of a
cout << *b << endl;
>> 10               // deference the address stored in b
cout << &b << endl;
>> 0x24fe40         // address of b
cout << c << endl;
>> 0x24fe40         // c stores address of b
cout << *c << endl;
>> 0x24fe4c         // deference the address stored in c -> which is address of a
cout << &c << endl;
>> 0x24fe38         // adress of c
cout << **c << endl;
>> 10               // doucle dereference c -> value at a
//---------------------------------- 

//================================================================================
//================================================================================



//====== Vectors =================================================================
//================================================================================
#include <vector>
vector<int> num;
    num.push_back(20);
    num.pop_back();

vector<int> v(4); // creates a vector with all 4 elements initialized to 0
vector<int> v(4, 100); // creates a vector with all 4 elements initialized to 100
v.size(); // No. elements in the vector
//while using v.size() -> typecast to int as it is unsigned int
int(v.size())

//------ 2D vector ------------
vector<vector<int>> b;
//================================================================================
//================================================================================


//======== Stack =================================================================
//================================================================================
#include <stack>
 stack<int> s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    s.pop();// cannot cout<< s.pop()
    cout<<s.top()<<endl;
>>2
>>1
s.empty();
#include <string>
stack<string> str;
str.push("aaaaa");
//================================================================================
//================================================================================


//======= Map ====================================================================
//================================================================================
#include <map>
map<string, int> m;
m["a"] = 1;
m["b"] = 2;
cout << map["a"];
>> 1
cout << map["b"];
>> 2

map<int, int> :: reverse_iterator i;
    
for(i = m.rbegin();i!=m.rend();i++){
        cout<<i->first;
        }
//================================================================================
//================================================================================


//======== Queue =================================================================
//================================================================================
#include <queue>
queue<int> q;
q.push(1);
q.push(2);
cout<< q.front() << endl;
1
cout << q.back() << endl;
2
q.pop() // remove the front element
cout << q.back() << endl;
2
//================================================================================
//================================================================================


//====== Priority Queue(Max heap) ================================================
//================================================================================
#include <queue>
 priority_queue<int> q;
    q.push(10);
    q.push(9);
    q.push(23);
    cout << q.top() << endl;
    >> 23
    q.pop();
    cout<< q.top() <<endl;
    >> 10

//Min heap
priority_queue<int, vector<int>, greater<int> > q;

struct compare  
{  
  bool operator()(const int& l, const int& r)  
  {  
      return l > r;  
  }  
};
priority_queue<int, vector<int>, compare > q;

//--------------------------------------------------------------------------------
class A{
public:
    int a;
    int b;
    A(int x,int y){a=x;y=b;}
    };
    
struct compare  
{  
  bool operator()(const A& l, const A& r)
  {  
      return l.a < r.a;  
  }  
}; 
    
int main(){
    priority_queue<A, vector<A>, compare > q;
    q.push(*(new A(1,10)));
    q.push(*(new A(4,40)));
    q.push(*(new A(4,30)));
    q.push(*(new A(5,50)));
    cout<<q.top().a;
    }
//================================================================================
//================================================================================

map<string, vector<int> > m;
vector<int> v1;v1.push_back(1);v1.push_back(2);v1.push_back(-2);
vector<int> v2;v2.push_back(100);v2.push_back(777);
   
m["a"] = v1;
m["b"] = v2;
   
map<string, vector<int> > :: iterator i;
for(i = m.begin(); i != m.end() ; i++){
    cout<< i->first<< endl;
    cout<< i->second[0] <<endl; // can iterate using simple for-loop
    }

//-------------------------------------------------------------------
map<string, vector<int> > m;
vector<int> v1;v1.push_back(1);v1.push_back(2);v1.push_back(-2);
vector<int> v2;v2.push_back(100);v2.push_back(777);
   
m["a"] = v1;
m["b"] = v2;
   
map<string, vector<int> > :: iterator i;
vector<int> :: iterator j;
for(i = m.begin(); i != m.end() ; i++){
    cout<< i->first<< endl;
    for(j = i->second.begin(); j != i->second.end(); j++){
        cout << *j << "\t";
        }
        cout<<endl;
    }
//-------------------------------------------------------------------


    map<string, vector <map<char,vector<int> > > > m; //;D
   vector<int> v1;v1.push_back(1);v1.push_back(2);v1.push_back(3);v1.push_back(4);
   vector<int> v2;v2.push_back(100);v2.push_back(50);v2.push_back(25);
   vector<int> v3;v3.push_back(-10);v3.push_back(-1);
   map<char, vector<int> > mv1; mv1['a'] = v1;
   map<char, vector<int> > mv2; mv2['b'] = v2;
   map<char, vector<int> > mv3; mv3['c'] = v3;
   vector<map<char, vector<int> > > vmv1; vmv1.push_back(mv1); vmv1.push_back(mv2);
   vector<map<char, vector<int> > > vmv2; vmv2.push_back(mv3);
   m["vatsal"] = vmv1;
   m["mahajan"] = vmv2;

    map<string, vector <map<char,vector<int> > > > :: iterator i;
    vector <map<char,vector<int> > > :: iterator j;
    map<char,vector<int> > :: iterator k;
    vector<int> :: iterator h;
    
    for(i = m.begin(); i != m.end() ;i++){
        cout<< i->first << endl;
        for(j = i->second.begin(); j != i->second.end() ; j++){
            for(k = j.begin(); k!= j.end() ; k++){
                cout<< k->first<<"\t";
                for(h = k->second.begin(); h != k->second.end(); h++){
                    cout<< *h <<"-";
                    }cout<<endl;
                }
            }
        }

//===================================================================================
//===================================================================================


//========================Validate BST===========================================================
//===================================================================================
public boolean isValidBST(TreeNode root) {
    return isValidBST(root, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY);    
}
 
public boolean isValidBST(TreeNode p, double min, double max){
    if(p==null) 
        return true;
 
    if(p.val <= min || p.val >= max)
        return false;
 
    return isValidBST(p.left, min, p.val) && isValidBST(p.right, p.val, max);
}

//====================Friend Funct=================================================
//=================================================================================

Friend int sum(classx obj);

//======================Friend Class ==============================================
//=================================================================================

class TwoValues {
int a;
int b;
public:
TwoValues(int i, int j) { a = i; b = j; }
friend class Min;
};

class Min {
public:
int min(TwoValues x);
};

int Min::min(TwoValues x)
{
return x.a < x.b ? x.a : x.b;
}

//=================================================================================
//=================================================================================

inline int max(int a, int b)
{
return a>b ? a : b;
}
int main()
{
cout << max(10, 20);
cout << " " << max(99, 88);
return 0;
}

//----------Equivalent-------------------------------------------------------------
int main()
{
cout << (10>20 ? 10 : 20);
cout << " " << (99>88 ? 99 : 88);
return 0;
}
//---------------------------------------------------------------------------------

class myclass {
int a, b;
public:
void init(int i, int j);
void show();
};
// Create an inline function.
inline void myclass::init(int i, int j)
{
a = i;
b = j;
}

//===============================Static============================================
//=================================================================================

No matter how many objects of a class
are created, only one copy of a static data member exists. Thus, all objects of that class
use that same variable. All static variables are initialized to zero before the first object
is created.

When you declare a static data member within a class, you are not defining it. (That
is, you are not allocating storage for it.) Instead, you must provide a global definition
for it elsewhere, outside the class. This is done by redeclaring the static variable using
the scope resolution operator to identify the class to which it belongs. This causes storage
for the variable to be allocated. (Remember, a class declaration is simply a logical
construct that does not have physical reality.)

class shared {
static int a;
int b;
public:
void set(int i, int j) {a=i; b=j;}
void show();
} ;

int shared::a; // define a
cout<<shared::a;

//=================================================================================
//=================================================================================



//====================Static Member Function ======================================
//=================================================================================

Member functions may also be declared as static. There are several restrictions placed
on static member functions. They may only directly refer to other static members of the
class. (Of course, global functions and data may be accessed by static member functions.)
A static member function does not have a this pointer.

class cl {
static int resource;
public:
static int get_resource();
void free_resource() { resource = 0; }
};

int cl::resource; // define resource

int cl::get_resource()
{
if(resource) return 0; // resource already in use
}

use: one good use for them is to "preinitialize" private static data before any object is actually created.

class static_type {
static int i;
public:
static void init(int x) {i = x;}
void show() {cout << i;}
};
int static_type::i; // define i
int main()
{
// init static data before object creation
static_type::init(100);
static_type x;
x.show(); // displays 100
return 0;
}

//=================================================================================
//=================================================================================

//====================================Global objects===============================
//=================================================================================
class myclass {
public:
int who;
myclass(int id);
~myclass();
} glob_ob1(1), glob_ob2(2);
Global objects are created before main.
//=================================================================================
//=================================================================================

//=================================================================================
//=================================================================================
int i; // global i
void f()
{
int i; // local i
::i = 10; // now refers to global i
.
.
.
}
//=================================================================================
//=================================================================================

//=================Object Assignment===============================================
//=================================================================================

Assuming that both objects are of the same type, you can assign one object to another.
This causes the data of the object on the right side to be copied into the data of the
object on the left.

myclass ob1, ob2;
ob1.set_i(99);
ob2 = ob1; // assign data from ob1 to ob2
//=================================================================================
//=================================================================================

//==============Pointer to Class Data Memeber===================================================================
//=================================================================================
class cl {
public:
cl(int i) { val=i; }
int val;
int double_val() { return val+val; }
};
int main()
{
int cl::*data; // data member pointer
int (cl::*func)(); // function member pointer
cl ob1(1), ob2(2); // create objects
data = &cl::val; // get offset of val
func = &cl::double_val; // get offset of double_val()
cout << "Here are values: ";
cout << ob1.*data << " " << ob2.*data << "\n";
cout << "Here they are doubled: ";
cout << (ob1.*func)() << " ";
cout << (ob2.*func)() << "\n";
return 0;
}
//=================================================================================
//=================================================================================

//=================New dynamic allocation==========================================
//=================================================================================
int *p ;
p = new int;
p = new int(8);
p = new int[]
//=================================================================================
//=================================================================================

//=================Copy Constructor================================================
//=================================================================================
 MyClass( const MyClass& other );
  MyClass( MyClass& other );
  MyClass( volatile const MyClass& other );
  MyClass( volatile MyClass& other );
//=================================================================================
//=================================================================================

//================== Operator overloading =========================================
//=================================================================================
loc loc::operator++()
{
longitude++;
latitude++;
return *this;
}

loc loc::operator=(loc op2)
{
longitude = op2.longitude;
latitude = op2.latitude;
return *this; // i.e., return object that generated call
}

//--------------------Using Friend Function operator overloading----------------------------------------

Since a friend function is not a member of the class, it
does not have a this pointer. Therefore, an overloaded friend operator function is passed
the operands explicitly.

When overloading a binary operator using a friend function, the left operand
is passed in the first parameter and the right operand is passed in the second parameter.

friend loc operator+(loc op1, loc op2); // now a friend
// Now, + is overloaded using friend function.
loc operator+(loc op1, loc op2)
{
loc temp;
temp.longitude = op1.longitude + op2.longitude;
temp.latitude = op1.latitude + op2.latitude;
return temp;
}

//---------------------------------------------------------------------------------
//=================================================================================
//=================================================================================

//================ Inheritance =================================================================
//=================================================================================
// Inherit multiple base classes.
class derived: public base1, public base2 {
public:
void set(int i, int j) { x=i; y=j; }
};

//--constructor

class base {
protected:
int i;
public:
base(int x) { i=x; cout << "Constructing base\n"; }
~base() { cout << "Destructing base\n"; }
};
class derived: public base {
int j;
public:
// derived uses x; y is passed along to base.
derived(int x, int y): base(y)
{ j=x; cout << "Constructing derived\n"; }
~derived() { cout << "Destructing derived\n"; }
void show() { cout << i << " " << j << "\n"; }
};
int main()
{
derived ob(3, 4);
ob.show(); // displays 4 3
return 0;
}

//--- access declaration
// here is access declaration
base::j; // make j public again , though was inherited privately

//---- Avoid ambi inherit--------------------------------------
ob.derived1::i = 10; // scope resolved, use derived1's i
//-------------------------------------------------------------

class base {
public:
int i;
};
// derived1 inherits base as virtual.
class derived1 : virtual public base {
public:
int j;
};
// derived2 inherits base as virtual.
class derived2 : virtual public base {
public:
int k;
};
/* derived3 inherits both derived1 and derived2.
This time, there is only one copy of base class. */
class derived3 : public derived1, public derived2 {
public:
int sum;
};
//=================================================================================
//=================================================================================

//=======================Pure Vitual=======================================================
//=================================================================================
virtual type func-name(parameter-list) = 0;
Keep in mind that when a virtual function is declared as pure, all derived classes
must override it. If a derived class fails to do this, a compile-time error will result.
//=================================================================================
//=================================================================================

//=======================Abstract Class============================================
//=================================================================================
A class that contains at least one pure virtual function is said to be abstract.
//=================================================================================
//=================================================================================

//=================Templates=======================================================
//=================================================================================
// This is a function template.
template <class X> void swapargs(X &a, X &b)
{
X temp;
temp = a;
a = b;
b = temp;
}
int i=10, j=20;
double x=10.1, y=23.3;
char a='x', b='z';
swapargs(i, j); // swap integers
swapargs(x, y); // swap floats
swapargs(a, b); // swap chars

template <class type1, class type2> void myfunc(type1 x, type2 y)

//---------------------------------------------------------------------------------
template <class Ttype> class class-name {
...
};
class-name <type> ob;

// This function demonstrates a generic stack.
#include <iostream>
using namespace std;
const int SIZE = 10;
// Create a generic stack class
template <class StackType> class stack {
StackType stck[SIZE]; // holds the stack
int tos; // index of top-of-stack
public:
stack() { tos = 0; } // initialize stack
void push(StackType ob); // push object on stack
StackType pop(); // pop object from stack
};
// Push an object.
template <class StackType> void stack<StackType>::push(StackType ob)
{
if(tos==SIZE) {
cout << "Stack is full.\n";
return;
}
stck[tos] = ob;
tos++;
}
// Pop an object.
template <class StackType> StackType stack<StackType>::pop()
{
if(tos==0) {
cout << "Stack is empty.\n";
return 0; // return null on empty stack
}
tos--;
return stck[tos];
}
int main()
{
// Demonstrate character stacks.
stack<char> s1, s2; // create two character stacks
int i;
s1.push('a');
s2.push('x');
s1.push('b');
s2.push('y');
s1.push('c');
s2.push('z');
for(i=0; i<3; i++) cout << "Pop s1: " << s1.pop() << "\n";
for(i=0; i<3; i++) cout << "Pop s2: " << s2.pop() << "\n";
// demonstrate double stacks
stack<double> ds1, ds2; // create two double stacks

ds1.push(1.1);
ds2.push(2.2);
ds1.push(3.3);
ds2.push(4.4);
ds1.push(5.5);
ds2.push(6.6);
for(i=0; i<3; i++) cout << "Pop ds1: " << ds1.pop() << "\n";
for(i=0; i<3; i++) cout << "Pop ds2: " << ds2.pop() << "\n";
return 0;
}
//=================================================================================
//=================================================================================

//============== Exception ========================================================
//=================================================================================
 try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }

    try
  {
    int* myarray= new int[1000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }

//========= Char Array ==string====================================================
//=================================================================================
  char p[] = "vatsal"; OR char p* = "vatsal";
    int i = 0;
    while(p[i]!='\0'){
        cout<<p[i];
        i++;}
cout <<p;
>>vatsal
//=================================================================================
//=================================================================================

//=========Strings=================================================================
//=================================================================================
string s = "vatsal";
cout << s.length();
>> 6

if(s[0] == 'v'){
        cout<<"Correct";
    }

char p[] = "vatsal"; OR char p* = "vatsal";
if(s == p){
        cout<<"Correct";
    }

string n = s.substr(2);
>>tsal

string n = s.substr(2,3);// second para is length after the firt idx specified
>>tsa

s.replace(2,3,"---"); //inplace
>>va---l

s.insert(2,"---"); //inplace
>>va---tsal

 int n = s.find("l");
 >> 5
//=================================================================================
//=================================================================================

//===================Sort==========================================================
//=================================================================================

 bool comp(A& l, A& r ){
    return l.a > r.a; 
    }
    
int main(){
    
    vector<A> v;
    v.push_back(*(new A(1,10)));
    v.push_back(*(new A(4,40)));
    v.push_back(*(new A(3,30)));
    v.push_back(*(new A(5,50)));    

    sort(v.begin(), v.end(), comp);

    vector<A> :: iterator i;
    for(i = v.begin();i!=v.end();i++){
        cout<<i->a;
        }
    }

sort(word.begin(), word.end());
sort(word.rbegin(), word.rend());
//=================================================================================
//=================================================================================

//=========================LCS======================================================
//=================================================================================

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}


//======Permutation========================================================================

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}