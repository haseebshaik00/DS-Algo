//#include<bits/stdc++.h> - includes every library
#include<iostream>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<unordered_map>
#define ll long long int
#define MAX_SIZE 100
#define MM 5
using namespace std;
typedef pair<int, pair<int,int>> node;

bool p[1000001]={false};
char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
unordered_map<int,int> m215;
ll coins[40];
int ans=0;

class Student
{
public:
    string name;
    int marks;
};

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

class Stack{
private:
    vector<int> v;
public:
    void push(int d)
    {
        v.push_back(d);
    }
    bool isEmpty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!isEmpty())
            v.pop_back();
    }
    int top()
    {
        return v[v.size()-1];
    }
};

class MinMaxStack
{
    vector<int> original_stack;
    vector<int> min_stack;
    vector<int> max_stack;

public:

    void push(int d)
    {
        int current_min=d;
        int current_max=d;

        if(min_stack.size())
        {
            current_min=min(min_stack[min_stack.size()-1],d);
            current_max=max(max_stack[max_stack.size()-1],d);
        }
        min_stack.push_back(current_min);
        max_stack.push_back(current_max);
        original_stack.push_back(d);
    }

    int top()
    {
        return original_stack[original_stack.size()-1];
    }

    int getMin()
    {
        return min_stack[min_stack.size()-1];
    }

    int getMax()
    {
        return max_stack[max_stack.size()-1];
    }

    void pop()
    {
        original_stack.pop_back();
        min_stack.pop_back();
        max_stack.pop_back();
    }

    bool empty()
    {
        return original_stack.size()==0;
    }
};

class Queue
{
    int *a;
    int cs,f,r,ms;

public:

    Queue(int ds=5)
    {
        a=new int[ds];
        cs=0;ms=ds;f=0;r=ms-1;
    }

    bool isFull()
    {
        return cs==ms;
    }

    bool isEmpty()
    {
        return cs==0;
    }

    void push(int d)
    {
        if(!isFull())
        {
            r=(r+1)%ms;
            a[r]=d;
            cs++;
        }
    }

    void pop()
    {
        if(!isEmpty())
        {
            f=(f+1)%ms;
            cs--;
        }
    }

    int front()
    {
        return a[f];
    }

    ~Queue()
    {
        if(a!=NULL)
        {
            delete []a;
            a=NULL;
        }
    }
};

class QueueList
{
    int cs;
    list<int> l;

public:
    QueueList()
    {
        cs=0;
    }

    bool isEmpty()
    {
        return cs==0;
    }

    void push(int d)
    {
        l.push_back(d);
        cs++;
    }

    void pop()
    {
        if(!isEmpty())
        {
            l.pop_front();
            cs--;
        }
    }
    int front()
    {
        return l.front();
    }
};

class StackFromQueue
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int d)
    {
        q1.push(d);
    }

    void pop()
    {
        if(q1.empty())
            return;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1,q2);
    }

    int top()
    {
        if(q1.empty())
            return 0;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int d=q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return d;
    }

    int sizein()
    {
        return q1.size()+q2.size();
    }
    bool isEmpty()
    {
        return sizein()==0;
    }
};

class QueueFromStack
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int d)
    {
        s1.push(d);
    }

    void pop()
    {
        if(s1.empty())
            return;
        while(s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while(s2.size()>0)
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int top()
    {
        if(s1.empty())
            return 0;
        while(s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int d=s1.top();
        s2.push(s1.top());
        s1.pop();
        while(s2.size()>0)
        {
            s1.push(s2.top());
            s2.pop();
        }
        return d;
    }

    int sizein()
    {
        return s1.size()+s2.size();
    }

    bool isEmpty()
    {
        return sizein()==0;
    }
};

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

class PairDiameter{
    public:
        int height;
        int diameter;
};

class PairHeightBalance{
    public:
        int height;
        bool balance;
};

class PairMaxSum
{
public:
    int branch_sum;
    int max_sum;
    PairMaxSum ()
    {
        branch_sum=0;
        max_sum = 0;
    }
};

class BSTLL
{
public:
    BinaryTreeNode *head;
    BinaryTreeNode *tail;
};

class Heap
{
    vector<int> v;
    bool minheap;

    bool compareHeap(int a, int b)
    {
        if(minheap)
            return a<b;
        else
            return a>b;
    }

    void heapify(int idx)
    {
        int lc = 2*idx;
        int rc = lc+1;
        int min_idx = idx;
        int last = v.size()-1;

        if(lc<=last && compareHeap(v[lc],v[idx]))
            min_idx = lc;
        if(rc<=last && compareHeap(v[rc],v[min_idx]))
            min_idx = rc;
        if(min_idx!=idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }

public:

    Heap(int default_size=10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minheap=type;
    }

    void push(int d)
    {
        v.push_back(d);
        int idx=v.size()-1;
        int parent = idx/2;
        while(idx>1 && compareHeap(v[idx],v[parent]))
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }

    int get()
    {
        return v[1];
    }

    bool isEmpty()
    {
        return v.size()==1;
    }

    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
};

class Person
{
public:
    string name;
    int age;
    Person()
    {
    }
    Person(string a,int b)
    {
        name=a;
        age=b;
    }
};

class Personcompare
{
public:
    bool operator()(Person A, Person B)
    {
        return A.age>B.age;
    }
};

class abc{
    public:
    int freq,num;
    abc(int freq,int num)
    {
        this->freq=freq;
        this->num=num;
    }
};
class functor{
    public:
    bool operator()(abc x1,abc x2)
    {
        if(x1.freq==x2.freq)
        return x1.num>x2.num;//When frequency of 2 elements is same, the smaller of the 2 elements will be at the top of the heap.
        else
        return x1.freq<x2.freq;//Max heap based on frequency count
    }
};

class HashtableNode
{
public:
    string key;
    int val;
    HashtableNode *next;

    HashtableNode(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~HashtableNode()
    {
        if(next!=NULL)
            delete next;
    }
};

class Hashtable
{
    HashtableNode **table;
    int current_size;
    int table_size;

    int hashFn(string key)
    {
        int idx=0,p=1;
        for(int j=0;j<key.length();j++)
        {
            idx += (key[j]*p)%table_size;
            idx %= table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n%2 == 0 || n%3 == 0)
            return false;
        for (int i=5; i*i<=n; i=i+6)
        {
            if (n%i == 0 || n%(i+2) == 0)
                return false;
        }
        return true;
    }

    int nextPrime(int N)
    {
        if (N <= 1)
            return 2;
        int prime = N;
        bool found = false;
        while (!found) {
            prime++;
            if (isPrime(prime))
                found = true;
        }
        return prime;
    }

    void rehash()
    {
        HashtableNode **oldTable = table;
        int oldTable_size = table_size;
        table_size = 2*table_size;
        table_size = nextPrime(table_size);
        table = new HashtableNode*[table_size];
        for(int i=0;i<table_size;i++)
            table[i]=NULL;
        for(int i=0;i<oldTable_size;i++)
        {
            HashtableNode *temp = oldTable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldTable!=NULL)
                delete oldTable[i];
        }
        delete []oldTable;
    }

public:
    Hashtable(int ts=5)
    {
        table_size = ts;
        current_size = 0;
        table = new HashtableNode*[table_size];
        for(int i=0;i<table_size;i++)
            table[i]=NULL;
    }

    void print()
    {
        for(int i=0;i<table_size;i++)
        {
            HashtableNode *temp = table[i];
            cout<<"Bucket "<<i<<" : ";
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<"="<<temp->val<<")->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

    void insert(string key, int val)
    {
        int idx = hashFn(key);
        HashtableNode *n = new HashtableNode(key,val);
        n->next = table[idx];
        table[idx]=n;
        current_size++;

        //rehashing and load factor
        float load_factor = current_size/(1.0 * table_size);
        float threshold_value = 2.0;
        if(load_factor > threshold_value) // then rehash
            rehash();
    }

    int* search(string key)
    {
        int idx = hashFn(key);
        HashtableNode *temp = table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
                return &temp->val;
            temp=temp->next;
        }
        return NULL; // for template class return NULL and make the return type of the function as T*
    }

    void erase(string key)
    {
        int idx = hashFn(key);
        HashtableNode *temp = table[idx];
        HashtableNode *prev = NULL;
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                if(prev!=NULL)
                    prev->next = temp->next;
                else
                    table[idx] = temp->next;
                temp->next = NULL; // necessary otherwise the delete temp will delete the whole LL starting from this node
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    int& operator[](string key)
    {
        int *f = search(key);
        if(f==NULL)
        {
            int garbage;
            insert(key,garbage);
            f=search(key);
        }
        return *f;
    }
};

class StudentMap
{
public:
    string fname;
    string lname;
    string rollno;

    StudentMap (string a, string b, string c)
    {
        fname=a;
        lname=b;
        rollno=c;
    }

    bool operator==(const StudentMap &s) const{
        return rollno == s.rollno?true:false;
    }
};

class HashFn
{
public:
    size_t operator()(const StudentMap &s)const
    //size_t is unsigned int data type used to represent size of some memory in bytes
    {
        return s.fname.length()+s.lname.length();
    }
};

class Point
{
public:
    int x,y;
    Point()
    {
    }
    Point(int a,int b)
    {
        x=a;y=b;
    }
};

class CompareRect
{
public:
    bool operator()(Point p1, Point p2)
    {
        if(p1.x==p2.x)
            return p1.y<p2.y;
        return p1.x<p2.x;
    }
};

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> children;
        bool terminal;

     TrieNode(char d){
            data = d;
            terminal = false;
        }
};

class Trie{

    TrieNode* root;
    int cnt;
public:

    Trie(){
        root = new TrieNode('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        TrieNode* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch))
                temp = temp->children[ch];
            else
            {
                TrieNode* n = new TrieNode(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w)
    {
        TrieNode* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch)==0)
                return false;
            else
                temp = temp->children[ch];
        }
        return temp->terminal;
    }
};

class TrieUniqueNodeUnique{
    public:
        char data;
        unordered_map<char, TrieUniqueNodeUnique*> children;
        bool terminal;
        int occ;

     TrieUniqueNodeUnique(char d){
            data = d;
            terminal = false;
            occ=0;
        }
};

class TrieUnique{

    TrieUniqueNodeUnique* root;
    int cnt;
public:

    TrieUnique(){
        root = new TrieUniqueNodeUnique('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        TrieUniqueNodeUnique* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch))
            {
                temp = temp->children[ch];
                temp->occ++;
            }
            else
            {
                TrieUniqueNodeUnique* n = new TrieUniqueNodeUnique(ch);
                n->occ++;
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    void printCount(char *w)
    {
        TrieUniqueNodeUnique* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch)==0)
                return;
            else
            {
                temp = temp->children[ch];
                cout<<w[i]<<" "<<temp->occ<<endl;
            }
        }
        cout<<endl;
    }

    void print(char *w)
    {
        string ans="";
        TrieUniqueNodeUnique* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            temp = temp->children[w[i]];
            ans += w[i];
            if(temp->occ==1)
            {
                cout<<ans<<endl;
                return;
            }
        }
        cout<<"-1"<<endl;
    }
};

class TrieNodeXor
{
public:
    TrieNodeXor *left; //for 0
    TrieNodeXor *right; //for 1

    TrieNodeXor()
    {
        left=NULL;
        right=NULL;
    }
};

class TrieXor
{
    TrieNodeXor *root;

public:
    TrieXor()
    {
        root = new TrieNodeXor();
    }

    //Insert
    void insert(int n)
    {
        TrieNodeXor *temp = root;
        for(int i=31 ; i>=0 ; i--)
        {
            int bit = (n>>i)&1;
            if(bit==0)
            {
                if(temp->left==NULL)
                    temp->left = new TrieNodeXor();
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                    temp->right = new TrieNodeXor();
                temp=temp->right;
            }
        }
    }

    //Xor helper function
    int maxXorVal(int val)
    {
        TrieNodeXor *temp=root;
        int current_ans = 0;
        for(int j=31;j>=0;j--)
        {
            int bit = (val>>j)&1;
            if(bit==0)
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                    current_ans += (1<<j);
                }
                else
                    temp=temp->left;
            }
            else
            {
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                    current_ans += (1<<j);
                }
                else
                    temp=temp->right;
            }
        }
        return current_ans;
    }

    //Max Xor Function
    int maxXor(int a[], int n)
    {
        int max_xor=0;
        for(int i=0;i<n;i++)
        {
            int val =a[i];
            insert(val);
            int curr_xor = maxXorVal(val);
            max_xor  = max(max_xor,curr_xor);
        }
        return max_xor;
    }
};

class TrieNodeDict{
    public:
        char ch;
        map<char, TrieNodeDict *> m;
        bool terminal;
        TrieNodeDict(char c)
        {
            ch=c;
            terminal=false;
        }
};

class TrieDict
{
    TrieNodeDict *root;
    public:

    TrieDict()
    {
        root=new TrieNodeDict('\0');
    }

    void insert(char w[])
    {
        TrieNodeDict *temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch=w[i];
            if(temp->m.count(ch))
                temp = temp->m[ch];
            else
            {
                TrieNodeDict* n = new TrieNodeDict(ch);
                temp->m[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    void print(TrieNodeDict *temp, string s, vector<string> &v)
    {
        if(temp->terminal)
            v.push_back(s);
        for(auto it:temp->m){
            s.push_back(it.first);
            print(it.second,s,v);
            s.pop_back();
        }

    }

    bool search(char w[], vector<string> &v)
    {
        TrieNodeDict* temp = root;
        string s="";
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->m.count(ch)==0){
                insert(w);
                return false;
            }
            else
            {
                s.push_back(ch);
                temp = temp->m[ch];
            }
        }
        print(temp, s, v);
        return true;
    }
};

class HuffmanTreeNode {
public:
	char data;
	int freq;
	HuffmanTreeNode* left;
	HuffmanTreeNode* right;
	HuffmanTreeNode(char character,int frequency)
	{
		data = character;
		freq = frequency;
		left = right = NULL;
	}
};

class CompareHuff {
public:
	bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b)
	{
		return a->freq > b->freq;
	}
};

void input_array(int a[], int n)
{
    for(int i=0;i<n;i++)
        cin>>a[i];
}

void input_2d_array(int a[][100], int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }

}

void display_2d_array(int a[][100], int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void display_array(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int linear_searchit(int a[], int n, int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
            return i+1;
    }
    return -1;
}

int binary_searchit(int a[], int n, int k)
{
    int m,s=0,e=n-1;
    while(s<=e)
    {
        m=(s+e)/2;
        if(a[m]==k)
            return m+1;
        else if(a[m]<k)
            s=m+1;
        else
            e=m-1;
    }
    return -1;
}

void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i; j<n; j++)
        {
            if(a[min_index]>a[j])
                min_index = j;
        }
        swap(a[i],a[min_index]);
    }
}

void bubble_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

void insertion_sort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        int e=a[i];

        while(j>=0 && e<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=e;
    }
}

void subarray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
                cout<<a[k]<<",";
            cout<<endl;
        }
    }
}

void subarray_max_sum1(int a[],int n)
{
    int max=INT_MIN,s=0,left=-1,right=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {   s=0;
            for(int k=i;k<=j;k++)
                s+=a[k];
            if(s>max)
                {
                    max=s;
                    left=i;
                    right=j;
                }
        }
    }
    for(int k=left;k<=right;k++)
        cout<<a[k]<<",";
    cout<<endl<<"max="<<max<<endl;
}

void subarray_max_sum2(int a[],int n)
{
    int b[n]={0},max=INT_MIN,s=0,left=-1,right=-1;
    b[0]=a[0];b[-1]=0;
    for(int i=1;i<n;i++)
        b[i]=b[i-1]+a[i];

    for(int i=0;i<n;i++)
        cout<<b[i]<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {   s=0;
            s=b[j]-b[i-1];
            if(s>max)
                {
                    max=s;
                    left=i;
                    right=j;
                }
        }
    }
    for(int k=left;k<=right;k++)
        cout<<a[k]<<",";
    cout<<endl<<"max="<<max<<endl;
}

void subarray_max_sum3(int a[],int n)
{
    int maxi=INT_MIN,s=0;
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
        if(s<0) s=0;
    }
    maxi=max(maxi,s);
    cout<<"Maximum Sum = "<<maxi<<endl;
}

void two_pointer_approach(int a[],int n)
{
    int i=0,j=n-1,s=0;
    int f;
    cout<<"Enter the sum to be found : ";
    cin>>f;
    while(i<j)
    {   s=a[i]+a[j];
        if(s<f)
            i++;
        else if(s>f)
            j--;
        else
        {
            cout<<a[i]<<"+"<<a[j]<<"="<<f<<endl;
            i++;j--;
        }
    }
}

bool char_array_palindrome(char a[])
{
    int j=strlen(a)-1;
    int i=0;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

void remove_duplicate(char a[])
{
    int i=0,j=1;
    while(a[j]!='\0')
    {
        if(a[i]==a[j])
            j++;
        else
            a[++i]=a[j];
    }
    a[++i]='\0';
    cout<<a<<endl;
    return;
}

int kadenceAlgo(int a[],int n)
{
	int cs=0,ms=0;
	for(int i=0;i<n;i++)
	{
		cs += a[i];
		if(cs<0)cs=0;
		ms=max(cs,ms);
	}
	return ms;
}

int maxSum(int a[],int n)
{
	int totalSum=0;
	int max1=kadenceAlgo(a,n);
	for(int i=0;i<n;i++)
	{
		totalSum += a[i];
		a[i] = -a[i];
	}
	int max2=totalSum+kadenceAlgo(a,n);
	return max(max1,max2);
}

int bitonic(int arr[], int n)
{
    int inc[n],dec[n];
    int i, max;

    inc[0] = 1;
    dec[n-1] = 1;

    for (i = 1; i < n; i++)
        inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    for (i = n-2; i >= 0; i--)
        dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
       {
           if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
       }
    return max;
}

bool comparator27(string a,string b)
{
	string p=a+b,q=b+a;
	if(p>q)
		return true;
	else
		return false;
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    int res[1000];
    res[0] = 1;
    int res_size = 1;
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}

char* mystrtok(char* str)
{
    static char* input = NULL;
    if (str != NULL) {
        input = str;
    }

    // Base case
    if (input == NULL)
        return NULL;

    // Array for storing tokens
    // +1 is for '\0'
    char* output = new char[strlen(input + 1)];

    int i = 0;

    // Storing the upper case character
    output[i] = input[i];

    i++;

    // Generating Tokens
    for (; input[i] != '\0'; i++) {
        if (!isupper(input[i]))
            output[i] = input[i];
        else {
            output[i] = '\0';
            input = input + i;
            return output;
        }
    }

    output[i] = '\0';
    input = NULL;
    return output;
}

void extractWords(char* s)
{

    // Extract 1st word and print it
    char* ptr = mystrtok(s);
    cout << ptr << endl;

    // Extract the remaining words
    while (ptr != NULL) {
        ptr = mystrtok(NULL);
        cout << ptr << endl;
    }
}

bool pal(char ch[],int i, int j)
{
	if(i>=j)
		return true;
	if(ch[i]!=ch[j])
		return false;
	return pal(ch,i+1,j-1);
}

int cMax(string s, int l, int k, char ch)
{
	int i=0,j=0,c=0,ans=0;
	for(;j<l-1;j++)
	{
		if(s[j]!=ch)
			c++;
		if(c==k)
			break;
	}
	while(i<j)
	{
		while(j<l-1 && s[j+1]==ch)
			j++;
		int cs=j-i+1;
		ans=(cs>ans)?cs:ans;
		i++;
		if(j<l-1 && s[i-1]!=ch)
			j++;
	}
	return ans;
}

long stoint(string s)
{
    long i,j=0;
    i = 0;
    while(s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');
        j++;
    }
    return i;
}

bool is_cb_number(string s)
{
    long long num = stoint(s);
    if (num == 0 || num == 1) {
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num == arr[i]) {
                return true;
            }
        }
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num % arr[i] == 0) {
                return false;
            }
        }
    return true;
}

bool is_valid(bool * visited, int l, int r)
{
    for(int i=l;i<r;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

bool compare39(int a, int b)
{
    return a<=b;
}

bool sort_sec(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}

int square_root(int n)
{
    int s=0,e=n,ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        int m=mid*mid;
        if(m==n)
            return mid;
        else if(m<n)
        {
            ans = mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

bool canPlaceCows(int a[], int n, int c, int min_step)
{
    int last_cow = a[0];
    int cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-last_cow >= min_step)
        {
            last_cow=a[i];
            if(++cnt>=c)            //It should be greater than equal to here
                return true;
        }
    }
    return false;
}

bool isPossible(int a[],int n, int m, int curr_min)
{
    int s=1;
    int read=0;
    for(int i=0;i<n;i++)
    {
        if(read+a[i]>curr_min)
        {
            s++;
            read=a[i];
            if(s>m)
                return false;
        }
        else
            read+=a[i];
    }
    return true;
}

int findPage(int a[], int n, int m)
{
    int ans=INT_MAX,e;
    for(int i=0;i<n;i++)
        e+=a[i];
    int s=a[n-1];
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(isPossible(a,n,m,mid))
        {
            e=mid-1;
            ans=min(ans,mid);
        }
        else
            s=mid+1;
    }
    return ans;
}

bool CanCookPrata(int cookRank[],int n,int time ,int P){

    int PrataMade=0;
    for(int i=0;i<n;i++){
        int t=0;//time
        int j=1;//multiplier
        int r=cookRank[i];
        while(t<time){
            t+=(r*j);
            if(t<=time)PrataMade++;
            if(PrataMade>=P)return true;
            j++;
        }
    }
    return false;

}

void solveThis()
{
    int p,c;
    cin>>p>>c;
    int r[c],ans=0;
    for(int i=0;i<c;i++)
        cin>>r[i];
    int s=1,e=((p*(p+1))/2)*8;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(CanCookPrata(r,c,mid,p))
        {
            ans = mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
    cout<<ans<<endl;
    return;
}

bool canGetScholarship(long int n, long int m, long int x, long int y, long int mid)
{
	if(mid*x<=m+(n-mid)*y)
		return true;
	return false;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void bitOddOrEven(int n)
{
    if(n&1==1)//if n=5 then n=101 & 1 changes to 001
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;
}

int getBit(int n, int i)
{
    int mask = (1<<i);
    int b = ((n&mask)>0)? 1 : 0;// n=5 and  i=1 then 101 & 010
    return b;
}

int setBit(int n, int i)
{
    int mask =(1<<i);
    int ans = (n|mask);
    return ans;
}

int clearBit(int n, int i)
{
    int mask = ~(1<<i);
    int ans = n&mask;
    return ans;
}

int updateBit(int n, int i, int m)
{
    int ans = clearBit(n,i);
    ans = ans|(m<<i);
    return ans;
}

int clearLastBits(int n, int i)
{
    int mask = (-1<<i);
    return (n&mask);
}

int clearRangeBits(int n, int i, int j)
{
    int ones=(~0);
    int a = ones<<(j+1);
    int b = ~(ones<<i);
    int mask = a|b;
    return (n&mask);
}

void subset(char c[],int n)
{
    int j=0;
    while(n>0)
    {
        int last_bit=(n&1);
        if(last_bit==1)
            cout<<c[j];
        j++;
        n=n>>1;
    }
    cout<<endl;
    return;
}

void primeSieve(int p[],int n)
{
    for(int i=3;i<=n;i+=2)
        p[i]=1;
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
                p[j]=0;
        }
    }
    p[2]=1;
    p[0]=p[1]=0;
    return;
}

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int pow_mod(int a,int b,int c)
{
	long long ans=1;
	while(b>0)
	{
		ans=ans*a;
		ans=ans%c;
		b--;
	}
	return ans;
}

long long int modpowIter(long long int a, long long int b, long long int c)
{
        long long int ans=1;
        while(b != 0) {
                if(b%2 == 1)
                        ans=(ans*a)%c;

                a=(a*a)%c;
                b /= 2;
        }
        return ans;
}

void primeSieveNew(bool p[], int n)
{
	for(int i=3;i<=n;i=i+2)
		p[i]=true;
	for(int i=3;i*i<=1000000;i++){
		if(p[i]){
			for(int j=i;j*i<=1000000;j++) p[i*j]=false;
		}
	}
	return;
}

int countPrimes(int a, int b)
{
	int c=0;
	for(int i=a;i<=b;i++)
	{
		if(p[i])
			c++;
	}
	return c;
}

int recFact(int n)
{
    if(n==0)
        return 1;
    return n*recFact(n-1);
}

int recFib(int n)
{
    if(n==0 or n==1)
        return n;
    return recFib(n-2)+recFib(n-1);
}

void recInc(int n)
{
    if(n==0)
        return;
    recInc(n-1);
    cout<<n<<" ";
}

void recDec(int n)
{
    if(n==0)
        return;
    cout<<n<<" ";
    recDec(n-1);
}

bool recSort(int a[],int n)
{
    if(n==1)
        return true;
    if(a[0]<a[1] and recSort(a+1,n-1))
        return true;
    return false;
}

int recBinarySearch(int a[], int s,int e, int key)
{
    if(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
            return mid;
        if(a[mid]>key)
            return recBinarySearch(a,s,mid-1,key);
        else
            return recBinarySearch(a,mid+1,e,key);
    }
    return -1;
}

int recPower(int a, int n)
{
    if(n==1)
        return a;
    return a*recPower(a,n-1);
}

int recMul(int a, int n)
{
    if(n==1)
        return a;
    return a+recMul(a,n-1);
}

int linearSearch1(int a[],int n,int key)
{
    if(n==0)
        return 0;
    if(a[0]==key)
        return 0;
    int i = linearSearch1(a+1,n-1,key);
    if(i==-1)
        return -1;
    return i+1;
}

int linearSearch2(int a[],int i,int n,int key)
{
    if(i==n)
        return -1;
    if(a[i]==key)
        return i;
    return linearSearch2(a, i+1, n, key);
}

int lastOccurence(int a[],int n,int key)
{
    if(n==0)
        return -1;
    int i = lastOccurence(a+1,n-1,key);
    if(i==-1)
    {
        if(a[0]==key)
            return 0;
        else
            return -1;
    }
    return i+1;
}

void allOccurence(int a[],int i, int n,int key)
{
    if(n==0)
        return;
    if(a[0]==key)
        cout<<i<<",";
    allOccurence(a+1,i+1,n-1,key);
}

int allStoredOccurence(int a[],int i, int n,int key,int b[],int j)
{
    if(n==0)
        return j;
    if(a[i]==key)
        b[j++]=i;
    allStoredOccurence(a,i+1,n-1,key,b,j);
}

void recBubbleSort(int a[],int n,int j)
{
    if(n==1)
        return;
    if(j==n-1)
        return recBubbleSort(a,n-1,0);
    if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    recBubbleSort(a,n,j+1);
    return;
}

void mergeThem(int a[],int s,int e)
{
    int mid=(s+e)/2;
    int t[100],i=s,j=mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];
    }
    while(i<=mid)
        t[k++]=a[i++];
    while(j<=e)
        t[k++]=a[j++];
    for(int i=s;i<=e;i++)
        a[i]=t[i];
}

void mergeSort(int a[],int s,int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    mergeThem(a,s,e);
}

int inversionMerge(int a[], int s, int e)
{
    int mid=(s+e)/2;
    int c=0,i=s,k=s,j=mid+1,temp[100];
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;i++;
        }
        else
        {
            c+=mid-i+1;
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=e)
        temp[k++]=a[j++];
    for(int i=s;i<=e;i++)
        a[i]=temp[i];
    return c;
}

int inversionCount(int a[],int s,int e)
{
    if(s>=e)
        return 0;
    int mid=(s+e)/2;
    int x=inversionCount(a,s,mid);
    int y=inversionCount(a,mid+1,e);
    int z=inversionMerge(a,s,e);
    return x+y+z;
}

int part(int a[],int s,int e)
{
    int p = a[e],i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(a[j]<=p)
            swap(a[++i],a[j]);
    }
    swap(a[i+1],a[e]);
    return (i+1);
}

void quickSort(int a[],int s,int e)
{
    if(s>=e)
        return;
    int p = part(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

void twoZeroFourEight(int n)
{
    if(n==0)
        return;
    twoZeroFourEight(n/10);
    cout<<words[n%10]<<" ";
    return;
}

int sti(char a[],int n)
{
    if(n==0)
        return 0;
    int last_digit = a[n-1]-'0';
    int small_Ans = sti(a,n-1);
    return small_Ans*10+last_digit;
}

void pi(char c[],int i)
{
    if(c[i]=='\0' || c[i+1]=='\0')
        return;
    if(c[i]=='p' && c[i+1]=='i')
    {
        int j=i+2;
        while(c[j]!='\0')
            j++;
        while(j>=i+2)
        {
            c[j+2]=c[j];
            j--;
        }
        c[i]='3';c[i+1]='.';c[i+2]='1';c[i+3]='4';
        pi(c,i+4);
    }
    else
        pi(c,i+1);
    return;
}

int tile(int n)
{
    if(n<=3)
        return 1;
    return tile(n-1)+tile(n-4);
}

int ladder(int n, int k)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=ladder(n-i,k);
    return ans;
}

void moveHanoi(int n,char src,char helper, char dest)
{
    if(n==0)
        return;
    moveHanoi(n-1,src,dest,helper);
    cout<<"Shift "<<n<<" from "<<src<<" to "<< dest<<endl;
    moveHanoi(n-1,helper,src,dest);
}

void generateSubsequence(char in[],char out[],int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=in[i];
    generateSubsequence(in,out,i+1,j+1);
    generateSubsequence(in,out,i+1,j);
}

void generateBrackets(char out[],int n, int idx, int open, int close)
{
    if(idx==2*n)
    {
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }

    if(open<n)
    {
        out[idx]='(';
        generateBrackets(out,n,idx+1,open+1,close);
    }
    if(close<open)
    {
        out[idx]=')';
        generateBrackets(out,n,idx+1,open,close+1);
    }
}

int profit(int n, int c, int w[],int p[])
{
    if(n==0||c==0)
        return 0;
    int inc,exc;
    inc=exc=0;
    if(w[n-1]<=c)
        inc=p[n-1]+profit(n-1,c-w[n-1],w,p);
    exc=profit(n-1,c,w,p);
    return max(inc,exc);
}

void phone(char c[],char d[],int i,int j)
{
    if(c[i]=='\0')
    {
        d[j]='\0';
        cout<<d<<endl;
        return;
    }
    int digit = c[i]-'0';
    if(digit==1||digit==0)
        phone(c,d,i+1,j);
    for(int k=0; keypad[digit][k]!='\0';k++)
    {
        d[j]=keypad[digit][k];
        phone(c,d,i+1,j+1);
    }
    return;
}

void generateStrings(char in[], char out[], int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    int digit = in[i]-'0';
    if(digit==0)
        generateStrings(in,out,i+1,j);
    else
    {
        char ch = digit + 'A' - 1;
        out[j]=ch;
        generateStrings(in,out,i+1,j+1);
    }

    if(in[i+1]!='\0')
    {
        int second_digit = in[i+1]-'0';
        int new_digit = digit*10+second_digit;
        if(new_digit<=26)
        {
            char ch1 = new_digit + 'A' - 1;
            out[j]=ch1;
            generateStrings(in,out,i+2,j+1);
        }
    }
    return;
}

bool maze(char maz[10][10], int output[10][10],int i, int j,int m, int n)
{
    if(i==m-1 && j==n-1)
    {
        output[i][j]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<output[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
        return true;
    }

    if(i>m-1||j>n-1)
        return false;
    if(maz[i][j]=='X')
        return false;

    output[i][j]=1;

    bool right_success = maze(maz,output,i,j+1,m,n);
    bool down_success = maze(maz,output,i+1,j,m,n);

    output[i][j]=0; //backtracking

    if(right_success||down_success)
        return true;
    return false;
}

void permute(char in[],int i,set<string> &s)
{
    if(in[i]=='\0')
    {
        s.insert(in);
        return;
    }

    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        permute(in,i+1,s);
        swap(in[i],in[j]);//backtracking
    }
}

bool isSafe(int chess[10][10],int n,int i,int j)
{
    for(int row=0;row<i;row++)
    {
        if(chess[row][j]==1)
            return false;
    }

    int x=i,y=j;
    while(x>=0 && y>=0)
    {
        if(chess[x][y]==1)
            return false;
        x--;y--;
    }

    x=i,y=j;
    while(x>=0 && y<n)
    {
        if(chess[x][y]==1)
            return false;
        x--;y++;
    }
    return true;
}

bool nqueen(int chess[10][10],int n,int i)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<chess[i][j]<<"_";
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(chess,n,i,j))
        {
            chess[i][j]=1;
            bool nextQueen = nqueen(chess,n,i+1);
            if(nextQueen)
                return true;
            chess[i][j]=0;
        }

    }
    return false;
}

bool canPlace(int sudoku[9][9],int n,int i,int j,int no)
{
    for(int x=0;x<n;x++)
    {
        if(sudoku[x][j]==no || sudoku[i][x]==no)
            return false;
    }
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(sudoku[x][y]==no)
                return false;
        }
    }
}

bool solvesudoku(int sudoku[9][9],int n,int i, int j)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<sudoku[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(j==n)
        return solvesudoku(sudoku,n,i+1,0);
    if(sudoku[i][j]!=0)
        return solvesudoku(sudoku,n,i,j+1);
    for(int no=1;no<=n;no++)
    {
        if(canPlace(sudoku,n,i,j,no))
        {
            sudoku[i][j]=no;
            bool canSolve = solvesudoku(sudoku,n,i,j+1);
            if(canSolve)
                return true;
        }
    }
    sudoku[i][j]=0;
    return false;
}

void bucketSort(Student s[100],int n)
{
    vector<Student> v[101];
    for(int i=0;i<n;i++)
    {
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }
    for(int i=100;i>=0;i--)
    {
        for(vector<Student>::iterator it = v[i].begin();it!=v[i].end();it++)
          cout<<(*it).name<<" "<<(*it).marks<<endl;
    }
    return;
}

void dnfSort(int a[],int n)
{
    int l=0,m=0,hi=n-1;
    while(m<hi)
    {
        if(a[m]==0)
        {
            swap(a[l],a[m]);
            l++;
            m++;
        }
        else if(a[m]==1)
            m++;
        else
        {
            swap(a[hi],a[m]);
            hi--;
        }
    }
    return;
}

void waveSort(int a[],int n)
{
    for(int i=0;i<n;i=i+2)
    {
        if(i!=0 and a[i]<a[i-1])
            swap(a[i],a[i-1]);
        else if(i!=n-1 and a[i]<a[i+1])
            swap(a[i],a[i+1]);
    }
}

ll optimalGame(ll i,ll j){
    if(i > j)
        return 0;
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;
    return max(pickFirst,pickLast);
}

void sumitup(int a[],int arr[],int t,int arri,int e,int s)
{
	if(t==0){
		for(int i=0;i<arri;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	if(t<0){
		return;
	}
	if(s>e){
		return;
	}
	int prev=-1;
	for(int i=s;i<=e;i++){
		if(a[i]!=prev){
			arr[arri]=a[i];
			prev=a[i];
			sumitup(a,arr,t-a[i],arri+1,e,i+1);
		}
	}
}

void funkyboard(int board[100][100],int r,int c,int n,int count)
{
    if(r>=n || c>=n || r<0 || c<0 || board[r][c]==0)
        return;

     ans = max(ans,count+1);
     board[r][c] = 0;

     funkyboard(board,r+1,c+2,n,count+1);
     funkyboard(board,r+1,c-2,n,count+1);
     funkyboard(board,r-1,c+2,n,count+1);
     funkyboard(board,r-1,c-2,n,count+1);
     funkyboard(board,r+2,c+1,n,count+1);
     funkyboard(board,r+2,c-1,n,count+1);
     funkyboard(board,r-2,c+1,n,count+1);
     funkyboard(board,r-2,c-1,n,count+1);

     board[r][c]=1;
}

int countLength(Node* head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

void insertAtHead(Node* &head,int d)
{
    if(head==NULL)
    {
        head=new Node(d);
        return;
    }

    Node *n = new Node(d);
    n->next=head;
    head=n;
    return;
}

void insertAtTail(Node* &head,int d)
{
    if(head==NULL)
        insertAtHead(head,d);
    Node *tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node *n= new Node(d);
    tail->next=n;
    return;
}

void insertAtMiddle(Node* &head,int d,int p)
{
    if(head==NULL or p==0)
        insertAtHead(head,d);
    else if(p>countLength(head))
        insertAtTail(head,d);
    else
    {
        Node *t = head;
        while(--p)
            t=t->next;
        Node *n = new Node(d);
        n->next=t->next;
        t->next=n;
    }
}

void printLL(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void deleteHead(Node* &head)
{
    if(head==NULL)
        return;
    Node *t=head->next;
    delete head;
    head=t;
}

void deleteTail(Node* &head)
{
    if(head==NULL)
        return;
    Node *t = head,*prev=NULL;
    while(t->next!=NULL)
    {
        prev=t;
        t=t->next;
    }
    delete t;
    prev->next=NULL;
}

void deleteFromMiddle(Node* &head,int p)
{
    if(p==0)
        deleteHead(head);
    else if(p>=countLength(head)-1)
        deleteTail(head);
    else
    {
        Node *t=head,*prev=NULL;
    while(p--)
    {
        prev=t;
        t=t->next;
    }
    prev->next=t->next;
    delete t;
    }
}

bool searchKey(Node* &head,int key)
{
    Node* t= head;
    while(t!=NULL)
    {
        if(t->data==key)
            return true;
        t=t->next;
    }
    return false;
}

Node* takeInput()
{
    Node* head=NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

istream& operator>>(istream&is, Node* &head)
{
    head=takeInput();
    return is;
}

ostream& operator<<(ostream&os,Node* head)
{
    printLL(head);
    return os;
}

void reverseLL(Node* &head)
{
    Node *t=head;
    Node *prev = NULL;
    Node *n;
    while(t!=NULL)
    {
        n=t->next;
        t->next=prev;
        prev=t;
        t=n;
    }
    head=prev;
}

Node* recReverseLL(Node* &head)
{
    if(head->next==NULL)
        return head;
    Node *small_head  = recReverseLL(head->next);
    Node* t = head->next;
    t->next=head;
    head->next=NULL;
    return small_head;
}

Node* findMiddle(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node* slow=head;
    Node* fast=head->next;
    //and because if or is taken then fast can't take
    //2 jumps if its next pointer is NULL and hence will lead to segmentation fault
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int kthNodeFromEnd(Node* head,int k)
{
    Node* slow =head;
    Node* fast=head;
    while(k--)
        fast=fast->next;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}

Node* mergeLL(Node* a,Node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node* c = NULL;
    if(a->data<b->data)
    {
        c=a;
        c->next=mergeLL(a->next,b);
    }
    else
    {
        c=b;
        c->next=mergeLL(a,b->next);
    }
    return c;
}

//takes same time as an array which is O(nlogn)
Node* mergeSortLL(Node* &head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* mid=findMiddle(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next=NULL;
    a=mergeSortLL(a);
    b=mergeSortLL(b);
    Node* c = mergeLL(a,b);
    return c;
}

bool detectCycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }
    return false;
}

void removeCycle(Node* &head)
{
    int c=0;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            c=1;
            break;
        }
    }
    if(c==1)
    {
        slow=head;
        while(fast->next==slow)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else
        return;
}

void insertCLL(Node* &head,int d)
{
    Node* n=new Node(d);
    Node* t=head;
    n->next=head;
    if(t!=NULL)
    {
        while(t->next!=head)
            t=t->next;
        t->next=n;
    }
    else
        n->next=n;
    head=n;
    return;
}

void printCLL(Node* head)
{
    Node* t=head;
    while(t->next!=head)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<t->data<<"->"<<"HEAD"<<endl;
    return;
}

Node* getNodeCLL(Node* head,int d)
{
    Node* t=head;
    while(t->next!=head)
    {
        if(t->data==d)
            return t;
        t=t->next;
    }
    if(t->data==d)
        return t;
    return NULL;
}

void deleteNodeCLL(Node* head,int d)
{
    Node* t=head;
    Node* del = getNodeCLL(head,d);
    if(t==del)
        head=head->next;
    while(t->next!=del)
        t=t->next;
    t->next=del->next;
    delete del;
}

void insertNodeBack(Node* &head, int d)
{
	if(head==NULL)
	{
		head=new Node(d);
		return;
	}
	Node *t=head;
	while(t->next!=NULL)
		t=t->next;
	t->next=new Node(d);
	return;
}

Node* kReverse(Node * &head,int k)
{
	Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    head->next = kReverse(next, k);

    return prev;
}

Node* arrange_LinkedList(Node* head)
{
   Node *oh=NULL,*ot=NULL,*eh=NULL,*et=NULL;
    Node * current=head;
    while(current!=NULL)
    {
        if((current->data)%2!=0)
        {
            if(oh==NULL)
            {
                oh=current;
                ot=current;
            }
            else{
                ot->next=current;
                ot=ot->next;
            }
            current=current->next;
        }
        else
        {
            if(eh==NULL)
            {
                eh=current;
                et=current;
            }
            else{
                et->next=current;
                et=et->next;
            }
            current=current->next;
        }
     }
     if(eh==NULL || oh==NULL)
        return head;
    if(et!=NULL)
    	et->next=NULL;
    if(ot!=NULL)
        ot->next=NULL;
    if(eh!=NULL && ot!=NULL)
        ot->next=eh;
  	head=oh;
    return head;
}

void arrange_LinkedListreverse(Node* &head_ref)
{
    Node *endi = head_ref;
    Node *prev = NULL;
    Node *curr = head_ref;

    while (endi->next != NULL)
        endi = endi->next;

    Node *new_end = endi;

    while (curr->data % 2 != 0 && curr != endi)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    if (curr->data%2 == 0)
    {
        head_ref = curr;
        while (curr != endi)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else prev = curr;
    if (new_end != endi && (endi->data) % 2 != 0)
    {
        prev->next = endi->next;
        endi->next = NULL;
        new_end->next = endi;
    }
    return;
}

void insertionSortitLL(Node* &sorted,Node* t)
{
	if(sorted==NULL || sorted->data >= t->data)
	{
		t->next=sorted;
		sorted=t;
	}
	else
	{
		Node* current = sorted;
		while(current->next!=NULL && current->next->data<t->data)
			current=current->next;
		t->next=current->next;
		current->next=t;
	}
}

void insertionSortLL(Node* &head)
{
	Node *t=head;
	Node *sorted = NULL;
	while(t!=NULL)
	{
		Node* next = t->next;
		insertionSortitLL(sorted,t);
		t=next;
	}
	head=sorted;
}

void transfer(stack<int> &s1,stack<int> &s2,int n)
{
    for(int i=0;i<n;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1)
{
    stack<int> s2;
    int n=s1.size();
    for(int i=0;i<n;i++)
    {
        int d=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(d);
        transfer(s2,s1,n-i-1);
    }
}

void insertAtBottom(stack<int> &s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int d=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(d);
}

void reverseStackRec(stack<int> &s)
{
    if(s.empty())
        return;
    int x=s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s,x);
}

bool balancedParenthesis(char c[])
{
    stack<char> s;
    for(int i=0;c[i]!='\0';i++)
    {
        char d=c[i];
        if(d=='(')
            s.push(d);
        else if(d==')')
        {
            if(s.empty() || s.top()!='(')
                return false;
            s.pop();
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        int curr_price = prices[i];
        while(!s.empty() and prices[s.top()]<=curr_price)
            s.pop();
        if(!s.empty())
        {
            int prev_highest = s.top();
            span[i]=i-prev_highest;
        }
        else
            span[i]=i+1;
        s.push(i);
    }
}

int getMaxArea(int hist[], int n)
{
    stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_top;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

bool isprime(long long int n)
{
    for (long long int i=2; i<=sqrt(n); i++)
        if (n%i == 0)
            return false;
    return true;
}

void sieve(vector<long long int> &v)
{
    vector<long long int> prime(100000,1);
    prime[0] = 0;
    prime[1] = 0;
    for(long long int i=3; i<=100000; i=i+2)
    {
        if(prime[i]==1)
        if(isprime(i)==true)
        {
            for(long long int j=3*i; j<=100000; j=j+2*i)
            prime[j]=0;
            v.push_back(i);
        }
    }
}

bool balancedParanthesisFull(char c[])
{
	stack<char> s;
	for(int i=0;c[i]!='\0';i++)
	{
		if(c[i]=='(' || c[i]=='{' || c[i]=='[')
			s.push(c[i]);
		else if(s.empty())
			return false;
		else
		{
			if(c[i]==')' && s.top()=='(')
				s.pop();
			else if(c[i]=='}' && s.top()=='{')
				s.pop();
			else if(c[i]==']' && s.top()=='[')
				s.pop();
            else
                return false;
		}
	}
	if(s.empty())
		return true;
	else
		return false;
}

bool DuplicateParenthisis(char c[],int n)
{
	stack<char> s;
	for(int i=0;c[i]!='\0';i++)
	{
		if(c[i]==')')
		{
			char top=s.top();
			s.pop();
			int chars=0;
			while(top!='(')
			{
				chars++;
				top=s.top();
				s.pop();
			}
			if(chars==0)
				return true;
		}
		else
			s.push(c[i]);
	}
	return false;
}

BinaryTreeNode* preorderBuild()
{
    int d;
    cin>>d;

    if(d==-1)
        return NULL;

    BinaryTreeNode *root = new BinaryTreeNode(d);
    root->left=preorderBuild();
    root->right=preorderBuild();
    return root;
}

BinaryTreeNode * levelorderBuild(BinaryTreeNode *root,int a[],int i,int n)
{
    if(i>n)
        return NULL;
    root = new BinaryTreeNode(a[i]);
    root->left = levelorderBuild(root->left,a,2*i+1,n);
    root->right = levelorderBuild(root->right,a,2*i+2,n);
    return root;
}

void preorderPrint(BinaryTreeNode *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(BinaryTreeNode *root)
{
    if(root==NULL)
        return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

void inorderPrint(BinaryTreeNode *root)
{
    if(root==NULL)
        return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int BinaryTreeHeight(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    int left_height = BinaryTreeHeight(root->left);
    int right_height = BinaryTreeHeight(root->right);
    return max(left_height,right_height) + 1;
}

void printKthlevel(BinaryTreeNode *root, int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);
    return;
}

void levelorderPrint(BinaryTreeNode *root)
{
    int height = BinaryTreeHeight(root);
    cout<<"Level Order : ";
    for(int i=0;i<height;i++)
        printKthlevel(root, i);
    cout<<endl;
}

void bfs(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode *f=q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
    return;
}

void bfs2(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BinaryTreeNode *f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            q.pop();
        cout<<f->data<<" ";
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
        }
    }
}

int nodeCount(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

int nodeSum(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    return root->data + nodeSum(root->left) + nodeSum(root->right);
}

int diameter(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    int h1 = BinaryTreeHeight(root->left);
    int h2 = BinaryTreeHeight(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}

PairDiameter fastDiameter(BinaryTreeNode *root){
    PairDiameter p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    PairDiameter left = fastDiameter(root->left);
    PairDiameter right = fastDiameter(root->right);
    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}

int sumReplacement(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    int left = sumReplacement(root->left);
    int right = sumReplacement(root->right);
    int temp = root->data;
    root->data = left + right;
    return temp + root->data;
}

PairHeightBalance isHeightBalanced(BinaryTreeNode *root)
{
    PairHeightBalance p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    PairHeightBalance left = isHeightBalanced(root->left);
    PairHeightBalance right = isHeightBalanced(root->right);
    p.height = max(left.height,right.height) + 1;
    if(abs(left.height-right.height)<=1 && left.balance && right.balance)
        p.balance = true;
    else
        p.balance = false;
    return p;
}

BinaryTreeNode *buildbbtreeFromArray(int a[],int s,int e)
{
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    BinaryTreeNode *root = new BinaryTreeNode(a[mid]);
    root->left = buildbbtreeFromArray(a,s,mid-1);
    root->right = buildbbtreeFromArray(a,mid+1,e);
    return root;
}

BinaryTreeNode * treeFromPreIn(int in[],int pre[],int s,int e)
{
    static int i = 0;   // static cz when the recursion comes back the variable will backtrack and we don't want that
    if(s>e)
        return NULL;
    BinaryTreeNode *root  = new BinaryTreeNode(pre[i]);
    int index = -1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    i++;
    root->left  = treeFromPreIn(in,pre,s,index-1);
    root->right = treeFromPreIn(in,pre,index+1,e);
    return root;
}

BinaryTreeNode * treeFromPostIn(int in[],int post[],int s,int e)
{
    static int i = 7;   // static cz when the recursion comes back the variable will backtrack and we don't want that
    if(s>e)
        return NULL;
    BinaryTreeNode *root  = new BinaryTreeNode(post[i]);
    int index = -1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==post[i])
        {
            index=j;
            break;
        }
    }
    i--;
    root->right = treeFromPostIn(in,post,index+1,e);
    root->left = treeFromPostIn(in,post,s,index-1);
    return root;
}

int search(int a[], int s, int e, int value)
{
    for (int i = s; i <= e; i++)
        if (a[i] == value)
            return i;
    return -1;
}

int *extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m+5];//increased size to avoid 0 size array .
    int j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            {
                newlevel[j] = level[i];
                j++;
            }
    return newlevel;
}

BinaryTreeNode *treeFromLevelIn(int in[], int level[], int s, int e,int n)
{
    if(s>e || n<=0)
        return NULL;
    BinaryTreeNode *root = new BinaryTreeNode(level[0]);
    if (s == e)
        return root;
    int i = search(in, s, e, root->data);
    int *llevel  = extrackKeys(in, level, i, n);
    int *rlevel  = extrackKeys(in + i + 1, level, n-1, n);//here u were usinf n-i-1 // e-i can also be used
    root->left = treeFromLevelIn(in, llevel, s, i-1, i-s);
    root->right = treeFromLevelIn(in, rlevel, i+1, e, e-i);
    return root;
}

BinaryTreeNode * treeFromPrePost(int pre[],int post[],int s,int e)
{
    static int i=0;
    if(s>e)
        return NULL;
    BinaryTreeNode *root  = new BinaryTreeNode(pre[i]);
    i++;
    int index = -1;
    for(int j=s;j<=e;j++)
    {
        if(post[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    if(index!=-1)
    {
        root->left = treeFromPrePost(pre,post,s,index);
        root->right = treeFromPrePost(pre,post,index+1,e);
    }
    return root;
}

BinaryTreeNode * treeFromPrePreM(int pre[],int prem[],int s,int e)
{
    static int i=0;
    if(s>e)
        return NULL;
    BinaryTreeNode *root = new BinaryTreeNode(pre[i]);
    i++;
    int index=-1;
    for (int j=s; j<=e;j++)
    {
        if (pre[i] == prem[j])
        {
            index=j;
            break;
        }
    }
    if(index!=-1)
    {
        root->left = treeFromPrePreM(pre,prem,index,e);
        root->right = treeFromPrePreM(pre,prem,s+1,index-1);
    }
    return root;
}

void mirror(BinaryTreeNode *root)
{
    if(root==NULL)
        return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}

void rightView(BinaryTreeNode *root, int level, int &maxlevel)
{
    if(root==NULL)
        return;
    if(level>maxlevel)
    {
        maxlevel=level;
        cout<<root->data<<" ";
    }
    rightView(root->right,level+1,maxlevel);
    rightView(root->left,level+1,maxlevel);
}

int printAtDistK(BinaryTreeNode *root, BinaryTreeNode *target, int k)
{
    if(root==NULL)
        return -1;
    if(root==target)
    {
        printKthlevel(target,k);
        return 0;
    }
    int DL = printAtDistK(root->left,target,k);
    if(DL!=-1)
    {
        if(DL+1==k)
            cout<<root->data<<" ";
        else
            printKthlevel(root->right,k-2-DL);
        return 1+DL;
    }
    int DR = printAtDistK(root->right,target,k);
    if(DR!=-1)
    {
        if(DR+1==k)
            cout<<root->data<<" ";
        else
            printKthlevel(root->left,k-2-DR);
        return 1+DR;
    }
    return -1;
}

BinaryTreeNode * lca(BinaryTreeNode *root, int a, int b)
{
    if(root==NULL)
        return NULL;
    if(root->data==a || root->data==b)
        return root;
    BinaryTreeNode *left = lca(root->left,a,b);
    BinaryTreeNode *right = lca(root->right,a,b);
    if(left!=NULL && right!=NULL)
        return root;
    if(left!=NULL)
        return left;
    return right;
}

PairMaxSum maxSumPath(BinaryTreeNode *root)
{
    PairMaxSum p;
    if(root==NULL)
        return p;
    PairMaxSum left = maxSumPath(root->left);
    PairMaxSum right = maxSumPath(root->right);
    int op1 = root->data;
    int op2 = left.branch_sum + root->data;
    int op3 = right.branch_sum + root->data;
    int op4 = left.branch_sum + right.branch_sum + root->data;

    int current_ans_through_root = max(op1,max(op2,max(op3,op4)));

    p.branch_sum = max(left.branch_sum,max(right.branch_sum,0))+root->data;
    p.max_sum = max(left.max_sum,max(right.max_sum,current_ans_through_root));
    return p;
}

int nodeLength(BinaryTreeNode *root, int key, int level)
{
    if(root==NULL)
        return -1;
    if(root->data==key)
        return level;
    int left = nodeLength(root->left,key,level+1);
    if(left!=-1)
        return left;
    return nodeLength(root->right,key,level+1);
}

int findDistance(BinaryTreeNode *root, int a, int b)
{
    BinaryTreeNode *la = lca(root,a,b);
    int l1 = nodeLength(la,a,0);
    int l2 = nodeLength(la,b,0);
    return l1+l2;
}

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void infixtopostfix(string c)
{
    stack<char> s;
    int n=c.length();
    string a;
    for(int i=0;i<n;i++)
    {
        if(c[i]>='a' && c[i]<='z' || c[i]>='A' && c[i]<='Z')
            a+=c[i];
        else if(c[i]=='(')
            s.push(c[i]);
        else if(c[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                char b=s.top();
                s.pop();
                a+= b;
            }
            if(s.top()=='(')
                s.pop();
        }
        else
        {
            while(!s.empty() && prec(c[i])<=prec(s.top()))
            {
                char b=s.top();
                s.pop();
                a+= b;
            }
            s.push(c[i]);
        }
    }
    while(!s.empty())
    {
        char b=s.top();
        s.pop();
        a+= b;
    }
    cout<<a<<endl;
}

bool isOperand(char c)
{
    return !(!isalpha(c) && !isdigit(c));
}

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return true;
    else
        return false;
}

void prefixtoinfix(string c)
{
    stack<string> s;
    int l=c.length();
    for(int i=l-1;i>=0;i--)
    {
        if(isOperator(c[i]))
        {
            string a=s.top();s.pop();
            string b=s.top();s.pop();
            s.push("("+a+c[i]+b+")");
        }
        else
            s.push(string(1,c[i]));
    }
    cout<<s.top();
}

void prefixtopostfix(string c)
{
    stack<string> s;
    int l=c.length();
    for(int i=l-1;i>=0;i--)
    {
        if(isOperator(c[i]))
        {
            string a=s.top();s.pop();
            string b=s.top();s.pop();
            s.push(a+b+c[i]);
        }
        else
            s.push(string(1,c[i]));
    }
    cout<<s.top();
}

void postfixtoprefix(string c)
{
    stack<string> s;
    int l=c.length();
    for(int i=0;i<l;i++)
    {
        if(isOperator(c[i]))
        {
            string a=s.top();s.pop();
            string b=s.top();s.pop();
            s.push(c[i]+b+a);
        }
        else
            s.push(string(1,c[i]));
    }
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout<<ans<<endl;
}

void postfixtoinfix(string c)
{
    stack<string> s;
    int l=c.length();
    for(int i=0;i<l;i++)
    {
        if(isOperator(c[i]))
        {
            string a=s.top();s.pop();
            string b=s.top();s.pop();
            s.push("("+b+c[i]+a+")");
        }
        else
            s.push(string(1,c[i]));
    }
    cout<<s.top()<<endl;
}

string infixtopostfix2(string c)
{
    stack<char> s;
    int n=c.length();
    string a;
    for(int i=0;i<n;i++)
    {
        if(c[i]>='a' && c[i]<='z' || c[i]>='A' && c[i]<='Z')
            a+=c[i];
        else if(c[i]=='(')
            s.push(c[i]);
        else if(c[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                char b=s.top();
                s.pop();
                a+= b;
            }
            if(s.top()=='(')
                s.pop();
        }
        else
        {
            while(!s.empty() && prec(c[i])<=prec(s.top()))
            {
                char b=s.top();
                s.pop();
                a+= b;
            }
            s.push(c[i]);
        }
    }
    while(!s.empty())
    {
        char b=s.top();
        s.pop();
        a+= b;
    }
    return a;
}

void infixtoprefix(string c)
{
    int l=c.length();
    reverse(c.begin(),c.end());
    for(int i=0;i<l;i++)
    {
        if(c[i]==')')
            c[i]='(';
        else if(c[i]=='(')
            c[i]=')';
    }
    string d=infixtopostfix2(c);
    reverse(d.begin(),d.end());
    cout<<d<<endl;
}

BinaryTreeNode *BSTinsertNode(BinaryTreeNode *bstroot, int d)
{
    if(bstroot==NULL)
        return new BinaryTreeNode(d);
    if(d<=bstroot->data)
        bstroot->left=BSTinsertNode(bstroot->left,d);
    else
        bstroot->right=BSTinsertNode(bstroot->right,d);
    return bstroot;
}

BinaryTreeNode *BSTbuild()
{
    int d;
    cin>>d;
    BinaryTreeNode *bstroot = NULL;
    while(d!=-1)
    {
        bstroot = BSTinsertNode(bstroot, d);
        cin>>d;
    }
    return bstroot;
}

bool BSTSearch(BinaryTreeNode *bstroot, int d)
{
    if(bstroot==NULL)
        return false;
    if(bstroot->data==d)
        return true;
    if(d<=bstroot->data)
        return BSTSearch(bstroot->left,d);
    else
        return BSTSearch(bstroot->right,d);
}

//https://ide.codingblocks.com/s/23088
BinaryTreeNode *BSTdelete(BinaryTreeNode *bstroot, int d)
{
    if(bstroot==NULL)
        return NULL;
    if(d<bstroot->data)
        bstroot->left = BSTdelete(bstroot->left,d);
    else if(d==bstroot->data)
    {
        if(bstroot->left==NULL && bstroot->right==NULL)
        {
            delete bstroot;
            return NULL;
        }
        else if(bstroot->left!=NULL && bstroot->right==NULL)
        {
            BinaryTreeNode *temp = bstroot->left;
            delete bstroot;
            return temp;
        }
        else if(bstroot->left==NULL && bstroot->right!=NULL)
        {
            BinaryTreeNode *temp = bstroot->left;
            delete bstroot;
            return temp;
        }
        else
        {
            BinaryTreeNode *temp = bstroot->right;
            while(temp->left!=NULL)
                temp=temp->left;
            bstroot->data = temp->data;
            bstroot->right = BSTdelete(bstroot->right,temp->data);
            return bstroot;
        }
    }
    else
        bstroot->right = BSTdelete(bstroot->right,d);
    return bstroot;
}

bool isBST(BinaryTreeNode *bstroot, int minV=INT_MIN, int maxV=INT_MAX)
{
    if(bstroot==NULL)
        return true;
    if(bstroot->data>minV && bstroot->data<maxV && isBST(bstroot->left, minV, bstroot->data) && isBST(bstroot->right, bstroot->data, maxV))
        return true;
    return false;
}

BSTLL flatten(BinaryTreeNode *bstroot)
{
    BSTLL l;
    if(bstroot==NULL)
    {
        l.head=NULL;
        l.tail=NULL;
        return l;
    }
    // Leaf Node
    if(bstroot->left==NULL && bstroot->right==NULL)
    {
        l.head=bstroot;
        l.tail=bstroot;
        return l;
    }
    // Left is Not NULL
    if(bstroot->left!=NULL && bstroot->right==NULL)
    {
        BSTLL leftLL = flatten(bstroot->left);
        leftLL.tail->right = bstroot;
        l.head = leftLL.head;
        l.tail=bstroot;
        return l;
    }
    //Right is Not NULL
    if(bstroot->left==NULL && bstroot->right!=NULL)
    {
        BSTLL rightLL = flatten(bstroot->right);
        bstroot->right = rightLL.head;
        l.head = bstroot;
        l.tail = rightLL.tail;
        return l;
    }
    //Both Sides are not NULL
    BSTLL leftLL = flatten(bstroot->left);
    BSTLL rightLL = flatten(bstroot->right);
    leftLL.tail->right = bstroot;
    bstroot->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

BinaryTreeNode *arraytoBST(BinaryTreeNode *bstroot, int a[], int s, int e, int n)
{
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    bstroot = new BinaryTreeNode(a[mid]);
    bstroot->left = arraytoBST(bstroot->left, a, s, mid-1, n);
    bstroot->right = arraytoBST(bstroot->right, a, mid+1, e, n);
    return bstroot;
}

int catalanNo(int n)
{
    return recFact(2*n)/(pow(recFact(n),2)*(n+1));
}

void helper(BinaryTreeNode *rt,map<int,pair<int,int>>&hashmap,int level,int hd){
	if(rt==NULL)return;
	if(hashmap.find(hd)==hashmap.end())
		hashmap.insert({hd,{rt->data,level}});
	else{
		pair<int ,int >p=hashmap[hd];
		if(level>=p.second)
			hashmap[hd]={rt->data,level};
	}
	helper(rt->left,hashmap,level+1,hd-1);
	helper(rt->right,hashmap,level+1,hd+1);
}

void TreeBottomView(BinaryTreeNode *rt){
	map<int,pair<int,int>>hashmap;
	helper(rt,hashmap,0,0);
	for(auto it:hashmap)
		cout<<it.second.first<<" ";
}

void buildHeap(vector<int> &v)
{
    for(int i=2;i<v.size();i++)
    {
        int idx=i;
        int parent=i/2;
        while(idx>1 && v[idx]>v[parent])
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent/=2;
        }
    }
}

void heapify(vector<int> &v, int idx)
{
    int lc = 2*idx;
    int rc = lc+1;
    int min_idx = idx;
    int last = v.size()-1;

    if(lc<=last && v[lc]>v[idx])// maxheap
        min_idx = lc;
    if(rc<=last && v[rc]>v[min_idx])
        min_idx = rc;
    if(min_idx!=idx)
    {
        swap(v[idx],v[min_idx]);
        heapify(v,min_idx);
    }
}

void buildHeapFast(vector<int> &v)
{
    for(int i=(v.size()-1)/2;i>=1;i--)
        heapify(v,i);
}

void heapifyHeapSort(vector<int> &v, int idx, int n)
{
    int lc = 2*idx;
    int rc = lc+1;
    int min_idx = idx;
    int last = n-1;

    if(lc<=last && v[lc]>v[idx])// maxheap
        min_idx = lc;
    if(rc<=last && v[rc]>v[min_idx])
        min_idx = rc;
    if(min_idx!=idx)
    {
        swap(v[idx],v[min_idx]);
        heapifyHeapSort(v,min_idx,n);
    }
}

void heapSort(vector<int> &v)
{
    buildHeapFast(v);
    int n=v.size();
    while(n>1)
    {
        swap(v[1],v[n-1]);
        n--;
        heapifyHeapSort(v,1,n);
    }
}

int joinRopes(int r[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(r,r+n);
    int cost=0;
    while(pq.size()>1)
    {
        int A=pq.top(); pq.pop();
        int B=pq.top(); pq.pop();
        cost += (A+B);
        pq.push(A+B);
    }
    return cost;
}

vector<int> mergeKsortedArrays(vector<vector<int>> v)
{
    vector<int> res;
    priority_queue<node, vector<node>, greater<node>> pq;
    for(int i=0;i<v.size();i++)
        pq.push({v[i][0],{i,0}});
    while(!pq.empty())
    {
        node p = pq.top();
        pq.pop();
        int element = p.first;
        int x=p.second.first;
        int y=p.second.second;
        res.push_back(element);
        if(y+1<v[x].size())
            pq.push({v[x][y+1],{x,y+1}});
    }
    return res;
}

int kthSmallest(int a[4][4],int n, int k)
{
    priority_queue<node, vector<node>, greater<node>> pq;
    int b[n][n]={0};
    for(int i=0;i<n;i++)
    {
        pq.push({a[0][i],{0,i}});
        b[0][i]=-1;
    }
    node ans;
    while(k--)
    {
        ans =pq.top();
        pq.pop();
        int element = ans.first;
        int i = ans.second.first;
        int j = ans.second.second;
        if(b[i+1][j]!=-1 && i+1<n)
        {
            pq.push({a[i+1][j],{i+1,j}});
            b[i+1][j]=-1;
        }
        if(b[i][j+1]!=-1 && j+1<n)
        {
            pq.push({a[i][j+1],{i,j+1}});
            b[i][j+1]=-1;
        }
    }
    return pq.top().first;
}

int kthSmallestOptimised(int a[4][4],int n, int k)
{
    priority_queue<node, vector<node>, greater<node>> pq;
    for(int i=0;i<n;i++)
        pq.push({a[0][i],{0,i}});
    node ans;
    while(k--)
    {
        ans=pq.top();
        pq.pop();
        int element = ans.first;
        int i = ans.second.first;
        int j = ans.second.second;
        if(i+1<n)
            pq.push({a[i+1][j],{i+1,j}});
    }
    return pq.top().first;
}

void kTop(int a[], int n, int k)
{
    vector<int> top(k + 1);
    unordered_map<int, int> freq;
    for (int m = 0; m < n; m++) {
    freq[a[m]]++;
    top[k] = a[m];
    auto it = find(top.begin(), top.end() - 1, a[m]);
    for (int i = distance(top.begin(), it) - 1; i >= 0; --i)
    {
        if (freq[top[i]] < freq[top[i + 1]])
            swap(top[i], top[i + 1]);
        else if ((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1]))
            swap(top[i], top[i + 1]);
        else
            break;
    }
    for (int i = 0; i < k && top[i] != 0; ++i)
        cout<<top[i]<<" ";
    }
    cout<<endl;
}

void verticalOrderPrint(BinaryTreeNode *root, int d, map<int,vector<int>> &m)
{
    if(root==NULL)
        return;
    m[d].push_back(root->data);
    verticalOrderPrint(root->left,d-1,m);
    verticalOrderPrint(root->right,d+1,m);
    return;
}

bool checkZeroSum(int a[], int n)
{
    unordered_set<int> s;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre += a[i];
        if(pre==0 or s.find(pre)!=s.end())
            return true;
        s.insert(pre);
    }
    return false;
}

int longestSubarrayZeroSum(int a[],int n)
{
    unordered_map<int,int> m;
    int pre=0,curr_len=0,max_len=0;
    for(int i=0;i<n;i++)
    {
        pre += a[i];
        if(pre==0)
        {
            curr_len=i+1;
            max_len=max(curr_len,max_len);
        }
        else if(m.find(pre)!=m.end())
        {
            curr_len=i-m[pre];
            max_len=max(curr_len,max_len);
        }
        else
            m[pre]=i;
    }
    return max_len;
}

int longestSubarrayKSum(int a[],int n, int k)
{
    unordered_map<int,int> m;
    int pre=0,curr_len=0,max_len=0;
    for(int i=0;i<n;i++)
    {
        pre += a[i];
        if(pre==k)
        {
            curr_len=i+1;
            max_len=max(curr_len,max_len);
        }
        else if(m.find(pre-k)!=m.end())
        {
            curr_len=i-m[pre-k];
            max_len=max(curr_len,max_len);
        }
        else
            m[pre]=i;
    }
    return max_len;
}

int largestConSubseq(int a[],int n)
{
    unordered_map<int,int> m; //number, streak length
    for(int i=0;i<n;i++)
    {
        int no = a[i];
        //New element whose left and right streak isn't present
        if(m.count(no-1)==0 and m.count(no+1)==0)
            m[no]=1;
        //Both sides streaks are present
        else if(m.count(no-1) and m.count(no+1))
        {
            int l1=m[no-1];
            int l2=m[no+1];
            int streak = 1+l1+l2;
            m[no-l1]=streak;
            m[no+l2]=streak;
        }
        //Right Expansion
        else if(m.count(no-1) and !m.count(no+1))
        {
            int len=m[no-1];
            m[no-len]=len+1;
            m[no]=len+1;
        }
        //Left Expansion
        else
        {
            int len=m[no+1];
            m[no+len]=len+1;
            m[no]=len+1;
        }
    }
    int largest=0;
    for(auto x:m)
        largest=max(largest,x.second);
    return largest;
}

int largestConSubseq2(int a[], int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]); //O(1) time
    int max_streak = 0;
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]-1)==s.end())
        {
            int next_no = a[i]+1;
            int streak_len=1;
            while(s.find(next_no)!=s.end())
            {
                streak_len++;
                next_no++;
            }
            max_streak=max(streak_len,max_streak);
        }
    }
    return max_streak;
}

string findMinWindow(string window, string pattern)
{
    int sl=window.length();
    int pl=pattern.length();

    //Corner Case
    if(pl>sl)
        return "None";

    //Freq Maps
    int fs[256]={0};
    int fp[256]={0};
    for(int i=0;i<pl;i++)
    {
        char ch=pattern[i];
        fp[ch]++;
    }

    //Sliding Window (Expansion + Contraction + Update the min window)
    int c=0;
    int strt=0; //left pointer to shrink the window
    int strt_idx=-1;
    int min_len = INT_MAX;
    for(int i=0;i<sl;i++)
    {
        char ch=window[i];
        fs[ch]++;

        //maintain the count of characters matched
        if(fp[ch]!=0 and fs[ch]<=fp[ch])
            c++;

        //start contracting from left
        if(c==pl)
        {
            char temp=window[strt];

            //loop to remove all unwanted characters
            while(fp[temp]==0 or fs[temp]>fp[temp])
            {
                fs[temp]--;
                strt++;
                temp=window[strt];
            }

            //window size
            int window_size = i-strt+1;
            if(window_size<min_len)
            {
                min_len=window_size;
                strt_idx=strt;
            }
        }
    }
    if(strt_idx==-1)
        return "None";
    string ans = window.substr(strt_idx,min_len);
    return ans;
}

int rightAngledTriangles(int a[][2], int n)
{
    unordered_map<int,int> x;
    unordered_map<int,int> y;
    for(int i=0;i<n;i++)
    {
        x[a[i][0]]++;
        y[a[i][1]]++;
    }
    int c=0;
    for(int i=0;i<n;i++)
        if(x[a[i][0]]>=1 && y[a[i][1]]>=1)
            c += (x[a[i][0]]-1)*(y[a[i][1]]-1);
    return c;
}

int countRects(vector<Point> cord)
{
    int n=cord.size();
    //insert all points in the set
    set<Point, CompareRect> s;
    for(int i=0;i<n;i++)
        s.insert(cord[i]);
    int ans=0;
    for(auto it=s.begin();it!=prev(s.end());it++)
    {
        for(auto jt=next(it);jt!=s.end();jt++)
        {
            Point p1=*it;
            Point p2=*jt;
            if(p1.x==p2.x or p1.y==p2.y)
                continue;
            Point p3(p1.x,p2.y);
            Point p4(p2.x,p1.y);
            if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
                ans++;
        }
    }
    return ans/2; // The p1 p2 repetition is already handled by the loop and this n/2 is because of the rectangle made when p1,p2 and p3,p4 are swapped
}

bool IsSorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++){
        if(arr[i]<arr[i+1]){
            return false;
        }
    }
    return true;
}

bool compe(int a,int b)
{
	return m215[a]<m215[b];
}

void hashFn215(int a[], int n, unordered_map<int,int> &m215, vector<int> &v)
{
	for(int i=0;i<n;i++)
	{
		if(m215.find(a[i])==m215.end())
			v.push_back(a[i]);
    	m215[a[i]]=i;
	}
}

int indianCoinGreedy(int a[], int n, int money)
{
    int ans=0;
    while(money>0)
    {
        int idx = upper_bound(a,a+n,money)-1-a;
        money -= a[idx];
        ans++;
    }
    return ans;
}

bool compBusyMan(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

bool compExp(pair<int,int> p1, pair<int,int>p2)
{
    return p1.first>p2.first;
}

bool compKnapsackGreedy(pair<int,int> p1, pair<int,int> p2)
{
    float pa = p1.first/(p1.second*1.0);
    float pb = p2.first/(p2.second*1.0);
    return pa > pb ;
}

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,CompareHuff> pq)
{
	while (pq.size() != 1)
    {
		HuffmanTreeNode* left = pq.top();
		pq.pop();
		HuffmanTreeNode* right = pq.top();
		pq.pop();
		HuffmanTreeNode* node = new HuffmanTreeNode('$', left->freq + right->freq);
		node->left = left;
		node->right = right;
		pq.push(node);
	}
	return pq.top();
}

void printCodes(HuffmanTreeNode* root, int arr[], int top)
{
	if (root->left)
    {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right)
    {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (!root->left && !root->right) {
		cout << root->data << " ";
		for (int i = 0; i < top; i++)
			cout << arr[i];
		cout << endl;
	}
}

void HuffmanCodes(char data[], int freq[], int size)
{
	priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, CompareHuff> pq;
	for (int i = 0; i < size; i++) {
		HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
		pq.push(newNode);
	}
	HuffmanTreeNode* root = generateTree(pq);
	int arr[MAX_SIZE], top = 0;
	printCodes(root, arr, top);
}

int fibrec(int n)
{
    if(n==0 || n==1)
        return n;
    return fibrec(n-1) + fibrec(n-2);
}

int fibTopDown(int n, int dp[])
{
    if(n==0 || n==1)
        return n;
    //Lookup
    if(dp[n]!=0)
        return dp[n];
    int ans = fibTopDown(n-1, dp) + fibTopDown(n-2, dp);
    return dp[n]=ans;
}

int fibBottomUp(int n)
{
    int dp[100]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int fibBottomUpOpt(int n)
{
    if(n==0 || n==1)
        return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int minStepsTopDown(int n, int dp[])
{
    if(n==1)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
        op3 = minStepsTopDown(n/3, dp);
    if(n%2==0)
        op2 = minStepsTopDown(n/2, dp);
    op1 = minStepsTopDown(n-1, dp);
    return dp[n] = min(op1,min(op2,op3)) + 1;
}

int minStepsBottomUp(int n)
{
    if(n==1)
        return 0;
    int dp[100]={0};
    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        op1 = dp[i-1];
        if(i%2==0)
            op2=dp[i/2];
        if(i%3==0)
            op3=dp[i/3];
        dp[i] = min(op1,min(op2,op3)) + 1;
    }
    return dp[n];
}

int minCoinsTopDown(int n, int coins[], int t, int dp[])
{
    if(n==0)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    int ans=INT_MAX;
    for(int i=0;i<t;i++)
    {
        if(n-coins[i]>=0)
        {
            int sub_prob = minCoinsTopDown(n-coins[i],coins,t,dp);
            ans = min(ans, sub_prob+1);
        }
    }
    return dp[n]=ans;
}

int minCoinsBottomUp(int n, int coins[], int t)
{
    if(n==0)
        return 0;
    int dp[100]={0};

    for(int i=1;i<=n;i++)
    {
        int sub_prob = INT_MAX;
        int ans=INT_MAX;
        for(int j=0;j<t;j++)
        {
            if(i-coins[j]>=0)
            {
                sub_prob = dp[i-coins[j]];
                ans = min(ans,sub_prob+1);
                dp[i]=ans;
            }
        }
    }
    return dp[n];
}

int winesProbTopDown(int a[], int i, int j, int y, int dp[][100])
{
    if(i>j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    return dp[i][j] = max(a[i]*y+winesProbTopDown(a,i+1,j,y+1,dp), a[j]*y+winesProbTopDown(a,i,j-1,y+1,dp));
}

int winesProbBottomUp(int a[],int n)
{
    int dp[100][100]={0};
    for(int i = n-1;i>=0;i--)
    {
        for(int j = 0;j<n;j++)
        {
            if(i > j)
                dp[i][j] = 0;
            else
                dp[i][j] = max((n - (j - i)) * a[i] + dp[i+1][j], (n - (j - i)) * a[j] + dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int maxSubarraySumDp(int a[],int n)
{
    int dp[100]={0};
    dp[0] = (a[0]>0)?a[0]:0;
    int overall_max = 0;
    for(int i=1;i<n;i++)
    {
        dp[i] = a[i] + dp[i-1];
        if(dp[i]<0)
            dp[i] = 0;
        overall_max = max(dp[i],overall_max);
    }
    return overall_max;
}

int laddersTopDown(int n, int k, int dp[])
{
    if(n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int ways = 0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
            ways += laddersTopDown(n-i,k,dp);
    }
    return dp[n] = ways;
}

int laddersBottomUp(int n, int k)
{
    int dp[100]={0};
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int laddersBottomUpOpt(int n, int k)
{
    int dp[100]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++)
        dp[i]=2*dp[i-1];
    for(int i=k+1;i<=n;i++)
        dp[i]=2*dp[i-1] - dp[i-k-1];
    return dp[n];
}

int rodCutting(int prices[], int n)
{
    if(n<=0)
        return 0;
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cut = i+1;
        int current_ans = prices[i] + rodCutting(prices, n-cut);
        ans =max(ans, current_ans);
    }
    return ans;
}

int rodCuttingTopDown(int prices[], int n, int dp[])
{
    if(n<=0)
        return 0;
    if(dp[n]!=0)
        return dp[n];
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cut = i+1;
        int current_ans = prices[i] + rodCuttingTopDown(prices, n-cut, dp);
        ans =max(ans, current_ans);
    }
    return dp[n]=ans;
}

int rodCuttingBottomUp(int prices[], int n)
{
    int dp[100]={0};
    for(int len=1;len<=n;len++)
    {
        int ans = INT_MIN;
        for(int i=0;i<len;i++)
        {
            int cut = i+1;
            int current_ans = prices[i] + dp[len-cut];
            ans = max(ans,current_ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int lcs(string s1, string s2, int i, int j)
{
    if(i==s1.length() or j==s2.length())
        return 0;
    if(s1[i]==s2[j])
        return 1 + lcs(s1,s2,i+1,j+1);
    int op1 = lcs(s1,s2,i+1,j);
    int op2 = lcs(s1,s2,i,j+1);
    return max(op1,op2);
}

int lcsTopDown(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if(i==s1.length() or j==s2.length())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
        return dp[i][j] = 1 + lcsTopDown(s1,s2,i+1,j+1,dp);
    int op1 = lcsTopDown(s1,s2,i+1,j,dp);
    int op2 = lcsTopDown(s1,s2,i,j+1,dp);
    return dp[i][j] = max(op1,op2); //final ans is stored at dp[0][0]
}

int lcsBottomUp(string s1,string s2)
{
    int n=s1.length(),m=s2.length();
    int dp[n+1][m+1]={-1};
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<dp[i][j];
        cout<<endl;
    }
    return dp[n][m];
}

int lisDP(int a[],int n)
{
    int dp[n]={0};
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int cmax=INT_MIN;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                cmax = max(cmax,dp[j]);
        }
        dp[i] = cmax+1;
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
    return ans;
}

int lis2(int a[],int n)
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=INT_MAX;
    dp[0] = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[j]<a[i] && a[i]<dp[j+1])
                dp[j+1]=a[i];
        }
    }
    int lis=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]!=INT_MAX)
            lis=i;
    }
    return lis;
}

int lis3(int a[],int n)
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=INT_MAX;
    dp[0] = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int j = upper_bound(dp,dp+n+1,a[i])-dp;
        if(dp[j-1]<a[i] && a[i]<dp[j])
            dp[j]=a[i];
    }
    int lis=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]!=INT_MAX)
            lis=i;
    }
    return lis;
}

int MatrixChainOrder(int a[], int n)
{
    n=n-1;
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n;i++) // i loop is for number of diagonals to be calculated
    {
        int r=0,c=i;
        while(c<n)
        {
            int val =INT_MAX;
            for(int pivot=r;pivot<c;pivot++)
                val = min(val, dp[r][pivot] + dp[pivot+1][c] + a[r]*a[pivot+1]*a[c+1]);
            dp[r][c] = val;
            r++;c++;
        }
    }
    return dp[0][n-1];
}

int cellMitosis(int n, int x, int y, int z)
{
    int dp[n+1]={0};
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        else
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
    }
    return dp[n];
}

int csumMixtures(int s, int e, int a[])
{
    int ans=0;
    for(int i=s;i<=e;i++)
    {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

int solveMixtures(int i, int j, int a[], int dp[][100])
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++)
        dp[i][j] = min(dp[i][j], solveMixtures(i,k,a,dp)+solveMixtures(k+1,j,a,dp)+csumMixtures(i,k,a)*csumMixtures(k+1,j,a));
    return dp[i][j];
}

int friendsPairing(int n)
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
            dp[i]=i;
        else
            dp[i] = dp[i-1] + (i-1) * dp[i-2];
    }
    return dp[n];
}

int optimalGameDP(int i, int j, int coins[], int dp[100][100])
{
    if(i>j)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int pickFirst = coins[i] + min( optimalGameDP(i+2,j,coins,dp) , optimalGameDP(i+1,j-1,coins,dp) ) ;
    int pickLast = coins[j] + min( optimalGameDP(i,j-2,coins,dp) , optimalGameDP(i+1,j-1,coins,dp) ) ;
    return dp[i][j] = max(pickFirst,pickLast);
}

int minCostPath(int r,int c, int a[][100])
{
    int dp[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0 && j==0)
                dp[i][j] = a[i][j];
            else if(i==0)
                dp[i][j] = dp[0][j-1] + a[0][j];
            else if(j==0)
                dp[i][j] = dp[i-1][0] + a[i][0];
            else
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j];
        }
    }
    return dp[r-1][c-1];
}

int robotDP(int m,int n, int dp[][100])
{
    if(dp[0][0]==-1)
        return 0;
    for(int k=0;k<n;k++)
    {
        if(dp[0][k]==-1)
            break;
        dp[0][k]=1;
    }
    for(int k=0;k<m;k++)
    {
        if(dp[k][0]==-1)
            break;
        dp[k][0]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j]==-1)
                continue;
            if(dp[i][j-1]!=-1)
                dp[i][j] = dp[i][j-1];
            if(dp[i-1][j]!=-1)
                dp[i][j] += dp[i-1][j];
        }
    }
    if(dp[m-1][n-1]==-1)
        return 0;
    return dp[m-1][n-1];
}

int func(int idx, int cur, int a[], int dp[MM][3], int n, int x)
{
    if (idx == n)
        return 0;

    if (dp[idx][cur] != -1)
        return dp[idx][cur];

    int ans = 0;
    if (cur == 0) {
        ans = max(ans, a[idx] + func(idx + 1, 0, a, dp, n, x));
        ans = max(ans, x * a[idx] + func(idx + 1, 1, a, dp, n, x));
    }
    else if (cur == 1) {
        ans = max(ans, x * a[idx] + func(idx + 1, 1, a, dp, n, x));
        ans = max(ans, a[idx] + func(idx + 1, 2, a, dp, n, x));
    }
    else
        ans = max(ans, a[idx] + func(idx + 1, 2, a, dp, n, x));
    return dp[idx][cur] = ans;
}

int getMaximumSum(int a[], int n, int x)
{
    int dp[n][3];
    memset(dp, -1, sizeof dp);
    int maxi = 0;
    for (int i = 0; i < n; i++)
       maxi = max(maxi, func(i, 0, a, dp, n, x));
    return maxi;
}

long long int binaryString(long long int n)
{
	long long int dp[n+1][2];
	dp[0][0]=dp[0][1]=0;
	dp[1][0]=dp[1][1]=1;
	for(long long int i=2;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	return dp[n][0]+dp[n][1];
}

void multiply(int F[2][2], int M[2][2])
{
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(int F[2][2], int n)
{
	if(n == 0 || n == 1)
	    return;
	int M[2][2] = {{1, 1},{1, 0}};
	power(F, n / 2);
	multiply(F, F);
	if (n % 2 != 0)
		multiply(F, M);
}

int fibMatrixExp(int n)
{
	int F[2][2] = {{1, 1},{1, 0}};
	if (n == 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}

int knapsackTopDownDP(int s,int w[],int p[],int dp[11][11],int i)
{
	if(i<0)
		return 0;
	if(dp[i][s]!=-1)
		return dp[i][s];
	int inc=0;int exc=0;
	if(w[i]<=s)
		inc = p[i] + knapsackTopDownDP(s-w[i],w,p,dp,i-1);
	exc  = knapsackTopDownDP(s,w,p,dp,i-1);
	return dp[i][s] = max(inc,exc);
}

int knapsackBottomUpDP(int s, int n, int w[],int p[])
{
	int dp[n+1][s+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(w[i-1]<=s)
                dp[i][j] = max(p[i-1]+dp[i-1][j-w[i-1]] , dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][s];
}

ll zeronKnapsack(ll s[],ll p[], ll n, ll c)
{
	ll dp[c+1];
	memset(dp,0,sizeof(dp));
	for(ll i=0;i<=c;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(s[j]<=i)
				dp[i] = max(dp[i],dp[i-s[j]] + p[j]);
		}
	}
	return dp[c];
}

int lcs3(string s1, string s2, string s3)
{
	int n1=s1.length(),n2=s2.length(),n3=s3.length();
	int dp[n1+1][n2+1][n3+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			for(int k=1;k<=n3;k++)
			{
			   if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
					dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				else
					dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
			}
		}
	}
	return dp[n1][n2][n3];
}

void removeDuplicateUnsorted(char c[], int n)
{
    map<char,int> m;
    vector<char> v;
    for(int i=0;i<strlen(c);i++)
        m.insert({c[i],1});
    for(int i=0;i<strlen(c);i++)
    {
        if(m[c[i]] == 1)
        {
            v.push_back(c[i]);
            m[c[i]] = -1;
        }
    }
    for(auto it=v.begin(); it!=v.end(); it++)
        cout<<*it<<" ";
}

void removeDuplicateSorted(char c[], int n)
{
    int i=0,j=1;
    while(c[j]!='\0')
    {
        if(c[i] == c[j])
            j++;
        else
            c[++i]=c[j];
    }
    c[++i]='\0';
    cout<<c<<endl;
}

int main()
{
    int ch;
    do{
    cout<<endl<<"******MENU******"<<endl;
    cout<<endl<<"*****Arrays*****"<<endl;
    cout<<"1. Linear Search"<<endl;
    cout<<"2. Binary Search"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cout<<"4. Bubble Sort"<<endl;
    cout<<"5. Insertion Sort"<<endl;
    cout<<"6. STL Sort"<<endl;
    cout<<"7. Subarrays"<<endl;
    cout<<"8. Max Subarray Sum O(n^3)"<<endl;
    cout<<"9. Max Subarray Sum O(n^2)"<<endl;
    cout<<"10. Max Subarray Sum O(n) - Kadane's Algorithm"<<endl;
    cout<<"11. Two Pointer Approach"<<endl;
    cout<<endl<<"*****2D Arrays*****"<<endl;
    cout<<"12. 2D Array Wave Print "<<endl;
    cout<<"13. 2D Array Spiral Print"<<endl;
    cout<<"14. Piyush and Magical Park - O(n^2) calculation part"<<endl;
    cout<<"15. Rotating Image"<<endl;
    cout<<"16. Staircase Search"<<endl;
    cout<<endl<<"*****Character Arrays*****"<<endl;
    cout<<"17. Check Palindrome using Character array"<<endl;
    cout<<"18. Remove consecutive duplicates"<<endl;
    cout<<"19. Largest Character Array"<<endl;
    cout<<endl<<"*****Strings*****"<<endl;
    cout<<"20. Sorting Strings"<<endl;
    cout<<endl<<"*****Problem Solving On 2D Arrays*****"<<endl;
    cout<<"21. Sum of all Submatrices O(n^6)"<<endl;
    cout<<"22. Sum of all Submatrices O(n^4)"<<endl;
    cout<<"23. Sum of all Submatrices O(n^2)"<<endl;
    cout<<endl<<"*****Arrays-Challenges*****"<<endl;
    cout<<"24. Maximum circular Subarray Sum"<<endl;
    cout<<"25. Maximum length of Bitonic Subarray"<<endl;
    cout<<"26. Rain Water Harvesting"<<endl;
    cout<<"27. Form Biggest Number"<<endl;
    cout<<"28. Broken Calculator - Factorial of Large Numbers"<<endl;
    cout<<"29. Sum of two arrays"<<endl;
    cout<<endl<<"*****Strings-Challenges*****"<<endl;
    cout<<"30. Extract CamelCase Strings-1"<<endl;
    cout<<"31. Extract CamelCase Strings-2"<<endl;
    cout<<"32. Palindrome string using recurssion"<<endl;
    cout<<"33. Strings-Max Frequency Character"<<endl;
    cout<<"34. Piyush and Magical Park - O(n) calculation part"<<endl;
    cout<<"35. String compression"<<endl;
    cout<<"36. Sanket and Strings"<<endl;
    cout<<"37. Coding Blocks Numbers"<<endl;
    cout<<endl<<"*****STL*****"<<endl;
    cout<<"38. Find STL"<<endl;
    cout<<"39. Money Change Problem"<<endl;
    cout<<"40. Next Permutation"<<endl;
    cout<<"41. Activity Selection Problem"<<endl;
    cout<<endl<<"*****Binary Search*****"<<endl;
    cout<<"42. Binary Search in a Sorted Rotated Array"<<endl;
    cout<<"43. Binary Search in Monotonic Spaces"<<endl;
    cout<<"44. Aggressive Cows (SPOJ)"<<endl;
    cout<<"45. Book Allocation"<<endl;
    cout<<"46. Parata (SPOJ)"<<endl;
    cout<<"47. Winning CodeBlocks Scholarship"<<endl;
    cout<<endl<<"*****Searching and Sorting-Challenges*****"<<endl;
    cout<<"48. Sting Sort Nishant"<<endl;
    cout<<"49. Count Sort-1"<<endl;
    cout<<"50. Count Sort-2"<<endl;
    cout<<"51. Upper Bound and Lower Bound"<<endl;
    cout<<endl<<"*****Base Conversions*****"<<endl;
    cout<<"52. Any Base to Decimal"<<endl;
    cout<<"53. Decimal to any Base"<<endl;
    cout<<endl<<"*****Bitmanipulation*****"<<endl;
    cout<<"54. Bit Manipulations"<<endl;
    cout<<"55. Unique Number - I"<<endl;
    cout<<"56. Unique Number - II"<<endl;
    cout<<"57. Unique Number - III"<<endl;
    cout<<"58. Exponent Optimised"<<endl;
    cout<<"59. Generate subsets using Bitmasking"<<endl;
    cout<<"60. The Incredible Hulk"<<endl;
    cout<<endl<<"*****Number Theory*****"<<endl;
    cout<<"61. Prime Numbers"<<endl;
    cout<<"62. Prime Factorization O(n)"<<endl;
    cout<<"63. Prime Factorization O(n^1/2)"<<endl;
    cout<<"64. Divisible Subarrays"<<endl;
    cout<<"65. GCD and LCM"<<endl;
    cout<<"66. Modular Exponentiation - O(b)"<<endl;
    cout<<"67. Modular Exponentiation - O(log(base-2)b)"<<endl;
    cout<<"68. Prime Visits (Sieve New)"<<endl;
    cout<<endl<<"*****Recurion*****"<<endl;
    cout<<"69. Recursive Factorial"<<endl;
    cout<<"70. Recursive Fibonacci"<<endl;
    cout<<"71. Recursive Increasing Decreasing"<<endl;
    cout<<"72. Recursive Sorted"<<endl;
    cout<<"73. Recursive Binary Search"<<endl;
    cout<<"74. Recursive Power"<<endl;
    cout<<"75. Recursive Multiplication"<<endl;
    cout<<"76. Recursive Linear Search First Ocurrence (2 methods)"<<endl;
    cout<<"77. Recursive Linear Search Last Ocurrence"<<endl;
    cout<<"78. Recursive All Occurrences"<<endl;
    cout<<"79. Recursive All Sorted Occurrences"<<endl;
    cout<<"80. Recursive Bubble Sort"<<endl;
    cout<<"81. Merge Sort"<<endl;
    cout<<"82. Inversion Count"<<endl;
    cout<<"83. Quick Sort"<<endl;
    cout<<"84. 2048 Problem"<<endl;
    cout<<"85. String to Int Recursion"<<endl;
    cout<<"86. Pi Recursion"<<endl;
    cout<<"87. Tiling Problem Recursion"<<endl;
    cout<<"88. Ladder Problem Recursion"<<endl;
    cout<<"89. Tower of Hanoi Problem"<<endl;
    cout<<"90. Generate Subset Recursion"<<endl;
    cout<<"91. Generate Brackets"<<endl;
    cout<<"92. 0-1 Knapsack Recursion"<<endl;
    cout<<"93. Phone Keypad Problem"<<endl;
    cout<<"94. Generate Acode Strings"<<endl;
    cout<<endl<<"*****Recurion-Backtracking*****"<<endl;
    cout<<"95. Rat in a maze Recursion"<<endl;
    cout<<"96. Permutation of strings"<<endl;
    cout<<"97. N-queen Backtracking"<<endl;
    cout<<"98. Sudoku Solver"<<endl;
    cout<<endl<<"*****Sorting Techniques*****"<<endl;
    cout<<"99. Bucket Sort"<<endl;
    cout<<"100. DNF Sort"<<endl;
    cout<<"101. Wave Sort"<<endl;
    cout<<endl<<"*****Recurion-Challenges*****"<<endl;
    cout<<"102. Optimal Game"<<endl;
    cout<<"103. Sum it Up"<<endl;
    cout<<"104. Funky Chess Board"<<endl;
    cout<<endl<<"******Linked List******"<<endl;
    cout<<"105. Insert"<<endl;
    cout<<"106. Delete"<<endl;
    cout<<"107. Search"<<endl;
    cout<<"108. Take input"<<endl;
    cout<<"109. Operator Overload"<<endl;
    cout<<"110. Reverse Linked List"<<endl;
    cout<<"111. Find the middle node"<<endl;
    cout<<"112. Find the kth node from last"<<endl;
    cout<<"113. Merge 2 Sorted Linked List"<<endl;
    cout<<"114. Merge Sort in Linked List"<<endl;
    cout<<"115. Linked List Floyd's Cycle Detection and Removal"<<endl;
    cout<<endl<<"******Circular Linked List"<<endl;
    cout<<"116. Insertion CLL"<<endl;
    cout<<"117. Deletion CLL"<<endl;
    cout<<"118. List STL - Adjacency List for Weighted Graph"<<endl;
    cout<<endl<<"******Linked List-Challenges******"<<endl;
    cout<<"119. K-Reverse"<<endl;
    cout<<"120. Even after odd LL"<<endl;
    cout<<"121. Odd after even LL"<<endl;
    cout<<"122. Insertion sort in LL"<<endl;
    cout<<endl<<"******Stack******"<<endl;
    cout<<"123. Stack using Vector"<<endl;
    cout<<"124. Stack STL"<<endl;
    cout<<"125. Reverse stack using only one extra stack"<<endl;
    cout<<"126. Reverse a stack recursively"<<endl;
    cout<<"127. Balanced Paranthesis"<<endl;
    cout<<"128. Stock Span Stack"<<endl;
    cout<<"129. Largest Histogram Area"<<endl;
    cout<<"130. Min Max Stack"<<endl;
    cout<<endl<<"******Queue******"<<endl;
    cout<<"131. Queue"<<endl;
    cout<<"132. Queue using List STL"<<endl;
    cout<<"133. Queue STL"<<endl;
    cout<<"134. First Non Repeating Character"<<endl;
    cout<<"135. Stack using 2 Queues"<<endl;
    cout<<"136. Queue using 2 Stacks"<<endl;
    cout<<endl<<"******Deque******"<<endl;
    cout<<"137. Maximum Element"<<endl;
    cout<<"138. Maximum length Unique Character Substring || Sliding Window || Not a Deque Problem"<<endl;
    cout<<endl<<"******Challenges - Stack, Queue and Deque******"<<endl;
    cout<<"139. Next Greater Element in an array"<<endl;
    cout<<"140. Next Greater Element in an Circular array"<<endl;
    cout<<"141. Playing  with cards"<<endl;
    cout<<"142. Balanced Parenthesis all 3 parenthsis"<<endl;
    cout<<"143. Redundant Parenthesis"<<endl;
    cout<<"144. Importance of Time"<<endl;
    cout<<endl<<"******Binary Tree******"<<endl;
    cout<<"145. Preorder Binary Tree Build and print in all orders"<<endl;
    cout<<"146. Height of Binary Tree"<<endl;
    cout<<"147. Level Order Print O(n^2)"<<endl;
    cout<<"148. BFS O(n)"<<endl;
    cout<<"149. BFS-2 O(n)"<<endl;
    cout<<"150. Nodes count and sum"<<endl;
    cout<<"151. Diameter of the tree O(n^2)"<<endl;
    cout<<"152. Diameter of the tree O(n)"<<endl;
    cout<<"153. Sum Replacement"<<endl;
    cout<<"154. Height Balanced Tree"<<endl;
    cout<<"155. Build Balanced Binary Tree from Array"<<endl;
    cout<<"156. Array from Preorder and Inorder"<<endl;
    cout<<"157. Mirror the binary tree"<<endl;
    cout<<"158. Right View"<<endl;
    cout<<"159. Print all the nodes at given distance K"<<endl;
    cout<<"160. Lowest Common Ancestor(LCA)"<<endl;
    cout<<"161. Maximum sum Path from any node to node"<<endl;
    cout<<"162. Shortest distance between any 2 nodes"<<endl;
    cout<<endl<<"******Some extra ques of Binary Tree******"<<endl;
    cout<<"163. Level Order Build and Print"<<endl;
    cout<<"164. Binary Tree from Preorder and Inorder"<<endl;
    cout<<"165. Binary Tree from Postorder and Inorder"<<endl;
    cout<<"166. Binary Tree from Levelorder and Inorder"<<endl;
    cout<<"167. Full Binary Tree from Preorder and Postorder"<<endl;
    cout<<"168. Full Binary Tree from Preorder and Preorder of it's mirror tree"<<endl;
    cout<<endl<<"******Stack Conversions (Infix, Postfix and Prefix)******"<<endl;
    cout<<"169. Infix to Postfix Conversion"<<endl;
    cout<<"170. Prefix to Infix Conversion"<<endl;
    cout<<"171. Prefix to Postfix Conversion"<<endl;
    cout<<"172. Postfix to Prefix Conversion"<<endl;
    cout<<"173. Postfix to Infix Conversion"<<endl;
    cout<<"174. Infix to Prefix Conversion"<<endl;
    cout<<endl<<"******Binary Search Trees******"<<endl;
    cout<<"175. Insertion and Build"<<endl;
    cout<<"176. Searching"<<endl;
    cout<<"177. Deletion"<<endl;
    cout<<"178. Check the tree BST or not"<<endl;
    cout<<"179. Flatten the BST"<<endl;
    cout<<"180. Balanced tree from a sorted array"<<endl;
    cout<<"181. Catalan Number"<<endl;
    cout<<endl<<"******Challenges - Binary Trees******"<<endl;
    cout<<"182. Bottom View"<<endl;
    cout<<endl<<"******Heaps******"<<endl;
    cout<<"183. Insertion and Deletion min/max Element"<<endl;
    cout<<"184. Converting Array/Vector into Heap(Inplace) - O(n logn)"<<endl;
    cout<<"185. Converting Array/Vector into Heap(Inplace) - O(n)"<<endl;
    cout<<"186. Heap Sort (Inplace)"<<endl;
    cout<<"187. Priority Queue STL"<<endl;
    cout<<"188. Priority Queue for Custom Classes"<<endl;
    cout<<"189. Join the Ropes"<<endl;
    cout<<"190. Running median of a integer stream"<<endl;
    cout<<"191. Merge k sorted Arrays"<<endl;
    cout<<"192. Kth Smallest Element in a sorted row and column Matrix"<<endl;
    cout<<"193. Kth Smallest Element in a sorted row and column Matrix Optimised"<<endl;
    cout<<endl<<"******Challenges - Heaps******"<<endl;
    cout<<"194. Hotel Visit"<<endl;
    cout<<"195. Top k most frequent number in a stream using Heap"<<endl;
    cout<<"196. Top k most frequent number in a stream using Hashmap"<<endl;
    cout<<endl<<"******Hashing/Hashing******"<<endl;
    cout<<"197. Hash Implementation"<<endl;
    cout<<"198. Map STL"<<endl;
    cout<<"199. Unordered Map STL Custom class"<<endl;
    cout<<"200. Unordered Map Phonebook"<<endl;
    cout<<"201. Vertical Order Print of a binary tree"<<endl;
    cout<<endl<<"******Challenges-Hashing/Hashing******"<<endl;
    cout<<"202. Check subarray with sum zero"<<endl;
    cout<<"203. Length of longest subarray with sum zero"<<endl;
    cout<<"204. Length of longest subarray with sum K"<<endl;
    cout<<"205. Longest Consecutive Subsequence using Unordered Map - O(n)"<<endl;
    cout<<"206. Longest Consecutive Subsequence using Unordered Set - O(n)"<<endl;
    cout<<"207. Minimum Window Substring - Sliding Window"<<endl;
    cout<<"208. Right Angled Triangles"<<endl;
    cout<<"209. Rectangle Counting"<<endl;
    cout<<endl<<"******Tries******"<<endl;
    cout<<"210. Trie Insertion and Search"<<endl;
    cout<<"211. Unique Prefix Array"<<endl;
    cout<<"212. Max Xor Pair"<<endl;
    cout<<"213. Unlock"<<endl;
    cout<<"214. Exist or Not"<<endl;
    cout<<"215. Mike And HashTrick"<<endl;
    cout<<"216. Subarrays with distinct elements"<<endl;
    cout<<"217. Digital Dictionary"<<endl;
    cout<<"218. Range Xor"<<endl;
    cout<<"219. Trie Interview"<<endl;
    cout<<endl<<"******Greedy Algorithms******"<<endl;
    cout<<"220. Indian Coin Change"<<endl;
    cout<<"221. Busy Man / Activity Selection Problem / Job scheduling Problem"<<endl;
    cout<<"222. Connecting Wires"<<endl;
    cout<<"223. Biased Standing"<<endl;
    cout<<"224. Load Balancer"<<endl;
    cout<<"225. Kingdom Defense"<<endl;
    cout<<"226. Chopsticks"<<endl;
    cout<<"227. Expedition"<<endl;
    cout<<"228. Fractional Knapsack Greedy"<<endl;
    cout<<"229. Huffman Coding"<<endl;
    cout<<endl<<"******Challenges - Greedy Algorithms******"<<endl;
    cout<<"230. Deepak and his journey"<<endl;
    cout<<"231. Dividing array"<<endl;
    cout<<endl<<"******Dynamic Programming******"<<endl;
    cout<<"232. Fibonacci Recursion"<<endl;
    cout<<"233. Fibonacci Top Bottom"<<endl;
    cout<<"234. Fibonacci Bottom Up"<<endl;
    cout<<"235. Fibonacci Bottom Up with Space Optimisation"<<endl;
    cout<<"236. Min Steps to One Top Down"<<endl;
    cout<<"237. Min Steps to One Bottom Up"<<endl;
    cout<<"238. Minimum Coin Change Top Down"<<endl;
    cout<<"239. Minimum Coin Change Bottom Up"<<endl;
    cout<<"240. Wines Problem Top Down"<<endl;
    cout<<"241. Wines Problem Bottom Up"<<endl;
    cout<<"242. Maximum Subarray Sum"<<endl;
    cout<<"243. Ladders Top Down"<<endl;
    cout<<"244. Ladders Bottom Up"<<endl;
    cout<<"245. Ladders Optimised Approach"<<endl;
    cout<<"246. Rod Cutting Problem"<<endl;
    cout<<"247. Rod Cutting Problem Top Down"<<endl;
    cout<<"248. Rod Cutting Problem Bottom Up"<<endl;
    cout<<"249. Longest Common Subsequence"<<endl;
    cout<<"250. Longest Common Subsequence Top Down"<<endl;
    cout<<"251. Longest Common Subsequence Bottom Up"<<endl;
    cout<<"252. Longest Increasing Subsequence DP:O(n^2)"<<endl;
    cout<<"253. Longest Increasing Subsequence DP-2:O(n^2)"<<endl;
    cout<<"254. Longest Increasing Subsequence DP-3 with binary search:O(nlogn)"<<endl;
    cout<<"255. Matrix Multiplication"<<endl;
    cout<<"256. Cell Mitosis"<<endl;
    cout<<"257. Mixtures SPOJ"<<endl;
    cout<<"258. Friends Pairing"<<endl;
    cout<<"259. Optimal Game Strategy DP"<<endl;
    cout<<"260. Minimum Cost Path DP"<<endl;
    cout<<"261. Robots DP"<<endl;
    cout<<endl<<"******Challenges - Dynamic Programming******"<<endl;
    cout<<"262. Maximize the subarray sum after multiplying all elements of any subarray with X"<<endl;
    cout<<"263. Count no. of Binary Strings"<<endl;
    cout<<"264. Fibonacci Matrix Exponentiation"<<endl;
    cout<<"265. 0-1 Knapsack Top Down DP"<<endl;
    cout<<"266. 0-1 Knapsack Bottom Up DP"<<endl;
    cout<<"267. 0-N Knapsack Bottom Up - O(w*n)"<<endl;
    cout<<"268. LCS of 3 strings"<<endl;
    cout<<"269. Longest Palindromic Subsequence"<<endl;
    cout<<endl<<"******Graphs******"<<endl;
    cout<<"270. Graph Adjacency List Implementation"<<endl;
    cout<<"271. Adjacency list implementation for generic data"<<endl;
    cout<<"272. BFS"<<endl;
    cout<<"273. Single source shortest path using BFS"<<endl;
    cout<<"274. Snake and Ladders"<<endl;
    cout<<"275. DFS"<<endl;
    cout<<"276. Connected components using DFS"<<endl;
    cout<<"277. DAG Topological Sort using DFS"<<endl;
    cout<<"278. Topological Sort using BFS"<<endl;
    cout<<"279. Undirected Graph is tree or not"<<endl;
    cout<<"280. Cycle Detection in Directed graph using DFS"<<endl;
    cout<<"281. Cycle Detection in Undirected graph using DFS"<<endl;
    cout<<"282. Djikstra's Algorithm"<<endl;
    cout<<endl<<"******Extras******"<<endl;
    cout<<"283. Target Sum Triplets"<<endl;
    cout<<"284. Remove Duplicate from unsorted array"<<endl;
    cout<<"285. Remove Duplicate from Sorted array"<<endl;
    cout<<"400. Exit"<<endl;
    cout<<endl<<"Enter your choice : ";
    cin>>ch;
    switch(ch)
        {
        case 1 :    {
                        int n,k;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        cout<<"Enter the key : ";
                        cin>>k;
                        int p = linear_searchit(a,n,k);
                        cout<<"The key is present at "<<p<<" position"<<endl;
                        break;
                    }
        case 2 :    {
                        int n,k;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        cout<<"Enter the key : ";
                        cin>>k;
                        int p = binary_searchit(a,n,k);
                        cout<<"The key is present at "<<p<<" position"<<endl;
                        break;
                    }
        case 3 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        selection_sort(a,n);
                        display_array(a,n);
                        break;
                    }
        case 4 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        bubble_sort(a,n);
                        display_array(a,n);
                        break;
                    }
        case 5 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        insertion_sort(a,n);
                        display_array(a,n);
                        break;
                    }
        case 6 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        sort(a,a+n);
                        display_array(a,n);
                        break;
                    }
        case 7 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray(a,n);
                        break;
                    }
        case 8 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray_max_sum1(a,n);
                        break;
                    }
        case 9 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray_max_sum2(a,n);
                        break;
                    }
        case 10 :   {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray_max_sum3(a,n);
                        break;
                    }
        case 11 :   {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the sorted array : ";
                        input_array(a,n);
                        two_pointer_approach(a,n);
                        break;
                    }
        case 12 :   {
                        int n,m;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<n;i++)
                        {
                            if(i%2==0)
                            {
                             for(int j=0;j<m;j++)
                                cout<<a[j][i]<<" ";
                            }
                            else
                            {
                                for(int j=m-1;j>=0;j--)
                                cout<<a[j][i]<<" ";
                            }
                        }
                        break;
                    }
        case 13 :   {
                        int m,n;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        //sr-start row ; sc- start column
                        int sr=0,sc=0,er=m-1,ec=n-1;
                        while(sc<=ec && sr<=er)
                        {
                            for(int i=sc;i<=ec;i++)
                                cout<<a[sr][i]<<" ";
                            sr++;
                            for(int i=sr;i<=er;i++)
                                cout<<a[i][ec]<<" ";
                            ec--;
                            if(er>sr)
                            {
                                 for(int i=ec;i>=sc;i--)
                                    cout<<a[er][i]<<" ";
                                 er--;
                            }
                            if(ec>sc)
                            {
                                for(int i=er;i>=sr;i--)
                                    cout<<a[i][sc]<<" ";
                                sc++;
                            }
                        }
                        break;
                    }
        case 14 :   {
                        int n,m,s,k;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        char a[m][n];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                                cin>>a[i][j];
                        }
                        cout<<"Enter the Strength : ";
                        cin>>s;
                        cout<<"Enter min weight : ";
                        cin>>k;
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                char c=a[i][j];
                                if(s<k)
                                {
                                    cout<<"No";
                                    return 0;
                                }
                                if(c=='.')
                                    s-=2;
                                else if(c=='*')
                                    s+=5;
                                else
                                    break;
                                if(j!=n-1)
                                    s--;
                            }
                        }
                        cout<<"Yes"<<endl<<s<<endl;
                        break;
                    }
        case 15 :   {
                        int m,n;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<m;i++)
                            reverse(a[i],a[i]+n);

                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<i;j++)
                                swap(a[i][j],a[j][i]);
                        }
                        display_2d_array(a,m,n);
                        break;
                    }
        case 16 :   {
                        int m,n,k,i;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        cout<<"Enter the key to Search : ";
                        cin>>k;i=0;
                        int j=n-1;
                        while(j>=0)
                        {
                            if(k==a[i][j])
                                {
                                    cout<<"Found at a["<<i+1<<"]["<<j+1<<"]"<<endl;
                                    break;
                                }
                            else if(k>a[i][j])
                                i++;
                            else
                                j--;
                        }
                        break;
                    }
        case 17 :   {
                        char a[100];
                        cout<<"Enter the string : ";
                        cin.get();
                        cin.getline(a,100);
                        if(char_array_palindrome(a))
                            cout<<"Palindrome"<<endl;
                        else
                            cout<<"Not Palindrome"<<endl;
                        break;
                    }
        case 18 :   {
                        char a[100];
                        cout<<"Enter the string : ";
                        cin.get();
                        cin.getline(a,100);
                        remove_duplicate(a);
                        break;
                    }
        case 19 :   {
                        int current_str_len=0,max_str_len=0,n;
                        char current_str[100],max_str[100];
                        cout<<"Enter the numebr of Strings : ";
                        cin>>n;
                        cin.get();
                        for(int i=0;i<n;i++)
                        {
                            cin.getline(current_str,100);
                            current_str_len=strlen(current_str);
                            if(current_str_len>max_str_len)
                                {
                                    strcpy(max_str,current_str);
                                    max_str_len=current_str_len;
                                }
                        }
                        cout<<max_str<<" "<<max_str_len<<endl;
                        break;
                    }
        case 20 :   {
                        int n;
                        cout<<"Enter the number of strings : ";
                        cin>>n;
                        string s[n];
                        cin.get();
                        for(int i=0;i<n;i++)
                            getline(cin,s[i]);
                        sort(s,s+n);
                        for(int i=0;i<n;i++)
                            cout<<s[i]<<endl;
                        break;
                    }
        case 21 :   {
                        int n,m,s=0,t=0;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                for(int k=i;k<m;k++)
                                {
                                    for(int l=j;l<n;l++)
                                    {   s=0;
                                        for(int p=i;p<=k;p++)
                                        {
                                            for(int q=j;q<=l;q++)
                                                {
                                                    s += a[p][q];
                                                    t += a[p][q];
                                                }
                                        }
                                        cout<<s<<endl;
                                    }
                                }
                            }
                        }
                        cout<<"Sum of all Submatrices = "<<t<<endl;
                        break;
                    }
        case 22 :   {
                        int n,m,s=0,t=0;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        int b[100][100]={0};
                        for(int i=0;i<m;i++)
                        {   s=0;
                            for(int j=0;j<n;j++)
                            {
                                s += a[i][j];
                                b[i][j]=s;
                            }
                        }
                        for(int j=0;j<n;j++)
                        {   s=0;
                            for(int i=0;i<m;i++)
                            {
                                s += b[i][j];
                                b[i][j]=s;
                            }
                        }
                        s=0;
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                            {   s=0;
                                for(int k=i;k<m;k++)
                                {
                                    for(int l=j;l<n;l++)
                                    {
                                        s=b[k][l]-b[i-1][l]-b[k][j-1]+b[i-1][j-1];
                                        cout<<s<<endl;
                                        t+=s;
                                    }
                                }
                            }
                        }
                        cout<<"Sum of all Submatrices = "<<t<<endl;
                        break;
                    }
        case 23 :   {
                        int n,m,s=0;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<m;j++)
                                s += a[i][j]*(i+1)*(j+1)*(n-i)*(m-j);
                        }
                        cout<<"Total Sum = "<<s<<endl;
                        break;
                    }
        case 24 :   {
                        int m;
                        cin>>m;
                        while(m>0)
                        {
                            int n;
                            cin>>n;
                            int a[n];
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            cout<<maxSum(a,n)<<endl;
                            m--;
                        }
                        break;
                    }
        case 25 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cout<<bitonic(a,n)<<endl;
                        break;
                    }
        case 26 :   {
                        int a[100], l[100], r[100];
                        int n, i, j;
                        cin >> n;
                        for (i = 0; i < n; i++)
                            cin >> a[i];
                        l[0] = a[0];
                        r[n - 1] = a[n - 1];
                        int leftmax = 0, rightmax = 0;
                        for (i = 1; i < n; i++)
                            l[i] = max(l[i - 1], a[i]);
                        for (i = n - 2; i >= 0; i--)
                            r[i] = max(r[i + 1], a[i]);
                        int water = 0;
                        for (i = 0; i < n; i++)
                            water += (min(l[i], r[i]) - a[i]);
                        cout << water;
                        break;
                    }
        case 27 :   {
                        int n;
                        cin>>n;
                        string a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        sort(a,a+n,comparator27);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 28 :   {
                        int n;
                        cin>>n;
                        factorial(n);
                        break;
                    }
        case 29 :   {
                        int n,m;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>m;
                        int b[m];
                        for(int i=0;i<m;i++)
                            cin>>b[i];
                        string a1="",b1="";
                        for(int i=0;i<n;i++)
                            a1=a1+to_string(a[i]);
                        for(int i=0;i<m;i++)
                            b1=b1+to_string(b[i]);
                        string d=to_string(stoi(a1)+stoi(b1));
                        for(int i=0;i<d.length();i++)
                            cout<<d[i]<<", ";
                        cout<<"END";
                        break;
                    }
        case 30 :   {
                        string ch;
                        cin>>ch;
                        for(int i=0;i<ch.length();i++)
                        {
                            int j=i+1;
                            if((ch[i]>='A' && ch[i]<='Z') && (ch[j]>='A' && ch[j]<='Z'))
                                cout<<ch[i]<<endl;
                            else  if((ch[i]>='a' && ch[i]<='z') && (ch[j]>='A' && ch[j]<='Z'))
                                cout<<ch[i]<<endl;
                            else if((ch[i]>='A' && ch[i]<='Z') && (ch[j]>='a' && ch[j]<='z'))
                                cout<<ch[i];
                            else
                                cout<<ch[i];
                        }
                        break;
                    }
        case 31 :   {
                        string s;
                        cin>>s;
                        char ch[s.length()+1];
                        strcpy(ch,s.c_str());
                        extractWords(ch);
                        break;
                    }
        case 32 :   {
                        int n;
                        cin>>n;
                        char ch[n];
                        cin.get();
                        for(int i=0;i<n;i++)
                            cin>>ch[i];
                        if(n==1 || n==0)
                        {
                            cout<<"true";
                            return 0;
                        }
                        if(pal(ch,0,n-1))
                            cout<<"true";
                        else
                            cout<<"false";
                        break;
                    }
        case 33 :   {
                        string s,ms;
                        cin>>s;
                        int max=0;
                        for(int i=0;i<s.length();i++)
                        {
                            int d=count(s.begin(),s.end(),s[i]);
                            if(d>max)
                            {
                                max=d;
                                ms=s[i];
                            }
                        }
                        cout<<ms;
                        break;
                    }
        case 34 :   {
                        int n,m,k,s;
                        cin>>n>>m>>k>>s;
                        char ch[n][m];
                        cin.get();
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<m;j++)
                                cin>>ch[i][j];
                        }
                        int i=0,j=0;
                        while(i<n)
                        {
                            if(s<k)
                            {
                                cout<<"No";
                                return 0;
                            }
                            if(j==m-1)
                            {
                                i++;
                                j=0;
                            }
                            else if(ch[i][j]=='.')
                            {
                                s = s-2-1;
                                j++;
                            }
                            else if(ch[i][j]=='*')
                            {
                                s = s+5-1;
                                j++;
                            }
                            else if(ch[i][j]=='#')
                            {
                                i++;
                                j=0;
                            }
                        }
                        if(s>=k)
                            cout<<"Yes"<<endl<<s;
                        else
                            cout<<"No";
                        break;
                    }
        case 35 :   {
                        string s;
                        getline(cin,s);
                        int cs=1;
                        for(int i=0;i<s.length();i++)
                        {
                            if(s[i]==s[i+1])
                                cs++;
                            else
                            {
                                cout<<s[i]<<cs;
                                cs=1;
                            }
                        }
                        break;
                    }
        case 36 :   {
                        int k;
                        cin>>k;
                        string s;
                        cin.get();
                        cin>>s;
                        int l=s.length();
                        int a=cMax(s,l,k,'a');
                        int b=cMax(s,l,k,'b');
                        cout<<max(a,b);
                        break;
                    }
        case 37 :   {
                        int n;
                        cin>>n;
                        string s;
                        cin>>s;
                        long count = 0;
                        bool* visited = new bool[n];
                        for(int i=0; i<s.length(); i++)
                        {
                            visited[i]=false;
                        }
                        for(int i=1; i <= s.length(); i++)
                        {
                            for(int j=0; j<=s.length()-i; j++)
                            {   int e = j+i;
                                string sub = s.substr(j, e-j);
                                if(is_cb_number(sub) && is_valid(visited,j,e))
                                {
                                    count++;
                                    for(int k=j;k<e;k++)
                                    {
                                        visited[k]=true;
                                    }
                                }
                            }
                        }
                        cout<<count<<endl;
                        break;
                    }
        case 38 :   {
                        int n,k;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        cout<<"Enter the key : ";
                        cin>>k;
                        int *it = find(a,a+n,k);
                        int index= it-a;
                        if(index==n)
                            cout<<"Not present"<<endl;
                        else
                            cout<<"Present at "<<index+1<<endl;
                        break;
                    }
        case 39 :   {
                        int coins[]={1,2,5,10,20,50,100,500,1000};
                        int money;
                        cout<<"Enter the amount : ";
                        cin>>money;
                        int n=9;
                        while(money>0)
                        {
                            int lb = lower_bound(coins,coins+n,money,compare39)-coins-1;
                            int m=coins[lb];
                            cout<<m<<",";
                            money=money-m;
                        }
                        break;
                    }
        case 40 :   {
                        int m;
                        cin>>m;
                        int a[m];
                        for(int i=0;i<m;i++)
                            cin>>a[i];
                        next_permutation(a,a+m);
                        for(int i=0;i<m;i++)
                            cout<<a[i]<<" ";
                        cout<<endl;
                        break;
                    }
        case 41 :   {
                        int n,c=1;
                        cin>>n;
                        pair<int,int> p[n];
                        for(int i=0;i<n;i++)
                            cin>>p[i].first>>p[i].second;
                        sort(p,p+n,sort_sec);
                        int j=0;
                        for(int i=1;i<n;i++)
                        {
                            if(p[i].first >= p[j].second){
                                j=i;
                                c++;
                            }
                        }
                        cout<<c<<endl;
                        break;
                    }
        case 42 :   {
                        int n,k;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int s=0,e=n-1;
                        cin>>k;
                        while(s<=e)
                        {
                            int m=(s+e)/2;
                            if(a[m]==k)
                                {
                                    cout<<m;
                                    break;
                                }
                            else if(a[s]<=a[m])
                            {
                                if(k>=a[s] && k<=a[m])
                                    e=m-1;
                                else
                                    s=m+1;
                            }
                            else
                            {
                                if(k>=a[m] and k<=a[e])
                                    s=m+1;
                                else
                                    e=m-1;
                            }
                        }
                        break;
                    }
        case 43 :   {
                        int n;
                        cin>>n;
                        cout<<square_root(n);
                        break;
                    }
        case 44 :   {
                        int n,c;
                        cin>>n>>c;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        sort(a,a+n);
                        int s=0,e=a[n-1];
                        int ans;
                        while(s<=e)
                        {
                            int mid = (s+e)/2;

                            bool c = canPlaceCows(a,n,c,mid);
                            if(c)
                            {
                                ans=mid;
                                s=mid+1;
                            }
                            else
                                e=mid-1;
                        }
                        cout<<ans<<endl;
                        break;
                    }
        case 45 :   {
                        int b,s;
                        cin>>b>>s;
                        int a[b];
                        for(int i=0;i<b;i++)
                            cin>>a[i];
                        cout<<findPage(a,b,s)<<endl;
                        break;
                    }
        case 46 :   {
                        int m;
                        cin>>m;
                        while(m--)
                            solveThis();
                        break;
                    }
        case 47 :   {
                        long int n,m,x,y;
                        cin>>n>>m>>x>>y;
                        long int s=0,e=n,ans=0;
                        while(s<=e)
                        {
                            long int mid=(s+e)/2;
                            if(canGetScholarship(n,m,x,y,mid))
                            {
                                ans=mid;
                                s=mid+1;
                            }
                            else
                                e=mid-1;
                        }
                        cout<<ans;
                        break;
                    }
        case 48 :   {
                        int n;
                        cin>>n;
                        cin.get();
                        string s[n];
                        for(int i=0;i<n;i++)
                            getline(cin,s[i]);
                        sort(s,s+n);
                        for(int i=0;i<n-1;i++)
                        {
                            if(s[i+1].find(s[i])==0)
                                swap(s[i],s[i+1]);
                        }
                        for(int i=0;i<n;i++)
                            cout<<s[i]<<endl;
                        break;
                    }
        case 49 :   {
                        long long int n;
                        cin>>n;
                        long long int a[n];
                        for(long long int i=0;i<n;i++)
                            cin>>a[i];
                        long long int max = *max_element(a,a+n);
                        long long int min = *min_element(a,a+n);
                        long long int range = max-min+1;

                        long long int count[range]={0},output[n];

                        for(long long int i=0;i<n;i++)
                            count[a[i]-min]++;
                        for(long long int i=1;i<range;i++)
                            count[i]+=count[i-1];
                        for(long long int i=n-1;i>=0;i--)
                        {
                            output[count[a[i] - min] - 1] = a[i];
                            count[a[i] - min]--;
                        }
                        for(long long int i=0;i<n;i++)
                            cout<<output[i]<<" ";
                        break;
                    }
        case 50 :   {
                        int n;
                        cin >> n;
                        int a[n];
                        int maxNum=0;
                        for (int i = 0; i < n; i++) {
                            cin >> a[i];
                            if(a[i]>maxNum){
                                maxNum=a[i];
                            }
                        }
                        int freq[maxNum+1] = {0};
                        for (int i = 0; i < n; i++) {
                            freq[a[i]]++;
                        }
                        int sortedA[n];
                        for (int i = 0; i < maxNum+1; i++) {
                            if(freq[i]!=0){
                                while(freq[i]--){
                                    cout << i<<" ";
                                }
                            }
                        }
                        break;
                    }
        case 51 :   {
                        int n,q;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                            int m;
                            cin>>m;
                            if(binary_search(a,a+n,m))
                                    cout<<lower_bound(a,a+n,m)-a<<" "<<(upper_bound(a,a+n,m)-1)-a<<endl;
                            else
                                cout<<"-1"<<" "<<"-1"<<endl;
                        break;
                    }
        case 52 :   {
                        char a[10];
                        cin>>a;
                        int base;
                        cin>>base;
                        int l=strlen(a), power=1, num=0;
                        for(int i=l-1;i>=0;i--)
                        {
                            if(val(a[i])>=base)
                                cout<<"Invalid number";
                            num+=val(a[i])*power;
                            power*=base;
                        }
                        cout<<num;
                        break;
                    }
        case 53 :   {
                        int n,base,index=0;
                        cin>>n>>base;
                        char a[100];
                        while(n>0)
                        {
                            a[index++]=reVal(n%base);
                            n/=base;
                        }
                        a[index]='\0';
                        reverse(a,a+index);
                        string s(a);
                        cout<<s;
                        break;
                    }
        case 54 :   {
                        int n,i,m;
                        cin>>n;
                        bitOddOrEven(n);
                        cout<<"Get Bit : ";
                        cin>>i;
                        cout<<getBit(n,i)<<endl;
                        cout<<"Set Bit : ";
                        cin>>i;
                        cout<<setBit(n,i)<<endl;
                        cout<<"Clear Bit : ";
                        cin>>i;
                        cout<<clearBit(n,i)<<endl;
                        cout<<"Update Bit"<<endl;
                        cout<<"Position number : ";
                        cin>>i;
                        cout<<"Updated to : ";
                        cin>>m;
                        cout<<updateBit(n,i,m)<<endl;
                        cout<<"Clear Last Bits"<<endl;
                        cout<<"No. of bits to be cleared from last : ";
                        cin>>i;
                        cout<<clearLastBits(n,i)<<endl;
                        cout<<"Clear Range Bits"<<endl;
                        cout<<"Enter the range : ";
                        cin>>i>>m;
                        cout<<clearRangeBits(n,i,m)<<endl;
                        cout<<"Total Bits : "<<__builtin_popcount(n);
                        break;
                    }
        case 55 :   {
                        int n,d,ans=0;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            cin>>d;
                            ans = ans^d;
                        }
                        cout<<ans;
                        break;
                    }
        case 56 :   {
                        int n,res=0,pos=0,ans1=0,ans2=0;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                        {
                            cin>>a[i];
                            res = res^a[i];
                        }
                        int res1=res;
                        while(pos=0)
                        {
                            if(res1&1==1)
                                pos++;
                            res>>1;
                        }
                        for(int i=0;i<n;i++)
                        {
                            if((a[i]&(1<<pos))!=0)
                                ans1 = ans1^a[i];
                        }
                        cout<<ans1<<" "<<(ans1^res)<<endl;
                        break;
                    }
        case 57 :   {
                        int n;
                        cin>>n;
                        int a[n],c[64]={0};
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        for(int i=0;i<n;i++)
                        {
                            int j=0;
                            int d=a[i];
                            while(d>0)
                            {
                                c[j]+=(d&1);
                                d=d>>1;
                                j++;
                            }
                        }
                        int p=1,ans=0;
                        for(int i=0;i<64;i++)
                        {
                            c[i]%=3;
                            ans = ans+c[i]*p;
                            p=p<<1;
                        }
                        cout<<ans;
                        break;
                    }
        case 58 :   {
                        int n,power;
                        cin>>n>>power;
                        int ans=1;
                        while(power>0)
                        {
                            int last_bit=(power&1);
                            if(last_bit==1)
                                ans*=n;
                            n*=n;
                            power=power>>1;
                        }
                        cout<<ans;
                        break;
                    }
        case 59 :   {
                        char c[10];
                        cin>>c;
                        int l=strlen(c);
                        for(int i=0;i<(1<<l);i++)
                            subset(c,i);
                        break;
                    }
        case 60 :   {
                        int n,ans=0,k;
                        cin>>n;
                        while(n>0)
                        {
                            int i=0;
                            while(i<n)
                            {
                                if(pow(2,i)<=n)
                                    k=i;
                                else
                                    break;
                                i++;
                            }
                            ans++;
                            n=n-pow(2,k);
                        }
                        cout<<ans<<endl;
                        break;
                    }
        case 61 :   {
                        int n;
                        cin>>n;
                        int p[n]={0};
                        primeSieve(p,n);
                        for(int i=0;i<=n;i++)
                        {
                            if(p[i]==1)
                                cout<<i<<" ";
                        }
                        break;
                    }
        case 62 :   {
                        int n,c=0;
                        vector<pair<int,int>> v;
                        cin>>n;
                        for(int i=2;i<=n;i++)
                        {
                            if(n%i==0)
                            {
                                while(n%i==0)
                                {
                                    n=n/i;
                                    c++;
                                }
                                v.push_back(make_pair(i,c));
                                c=0;
                            }
                        }
                        for(auto it : v)
                            cout<<it.first<<"^"<<it.second<<endl;
                        break;
                    }
        case 63 :   {
                        int n,c=0;
                        vector<pair<int,int>> v;
                        cin>>n;
                        for(int i=2;i*i<=n;i++)
                        {
                            if(n%i==0)
                            {
                                while(n%i==0)
                                {
                                    n=n/i;
                                    c++;
                                }
                                v.push_back(make_pair(i,c));
                                c=0;
                            }
                        }
                        if(n!=1)
                            v.push_back(make_pair(n,1));
                        for(auto it : v)
                            cout<<it.first<<"^"<<it.second<<endl;
                        break;
                    }
        case 64 :   {
                        int pre[1000]={0}; //to store count of each index(number)
                        int n,sum=0,ans=0;
                        cin>>n;
                        int a[n];
                        pre[0]=1;
                        for(int i=0;i<n;i++)
                        {
                            cin>>a[i];
                            sum+=a[i];
                            sum %= n;
                            sum = (sum+n)%n;    //if sum becomes negative
                            pre[sum]++;
                        }
                        for(int i=0;i<n;i++)
                        {
                            int m=pre[i];
                            ans += m*(m-1)/2;
                        }
                        cout<<ans;
                        break;
                    }
        case 65 :   {
                        int a,b;
                        cin>>a>>b;
                        int g=gcd(a,b);
                        cout<<"GCD = "<<g<<endl;
                        cout<<"LCM = "<<(a*b)/g;
                        break;
                    }
        case 66 :   {
                        int a,b,c;
                        cin>>a>>b>>c;
                        cout<<pow_mod(a,b,c);
                        break;
                    }
        case 67 :   {
                        long long int a,b,c;
                        cin>>a>>b>>c;
                        cout<<modpowIter(a,b,c);
                        break;
                    }
        case 68 :   {
                        p[0]=p[1]=false;p[2]=true;
                        primeSieveNew(p,1000001);
                        int t;
                        cin>>t;
                        while(t--)
                        {
                            int a,b;
                            cin>>a>>b;
                            cout<<countPrimes(a,b)<<endl;
                        }
                        break;
                    }
        case 69 :   {
                        int n;
                        cin>>n;
                        cout<<recFact(n)<<endl;
                        break;
                    }
        case 70 :   {
                        int n;
                        cin>>n;
                        cout<<recFib(n)<<endl;
                        break;
                    }
        case 71 :   {
                        int n;
                        cin>>n;
                        recDec(n);
                        cout<<endl;
                        recInc(n);
                        break;
                    }
        case 72 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cout<<recSort(a,n);
                        break;
                    }
        case 73 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        cout<<recBinarySearch(a,0,n-1,key)<<endl;
                        break;
                    }
        case 74 :   {
                        int a,n;
                        cin>>a>>n;
                        cout<<recPower(a,n)<<endl;
                        break;
                    }
        case 75 :   {
                        int a,n;
                        cin>>a>>n;
                        cout<<recMul(a,n)<<endl;
                        break;
                    }
        case 76 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        cout<<linearSearch1(a,n,key)<<endl;
                        cout<<linearSearch2(a,0,n,key)<<endl;
                        break;
                    }
        case 77 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        cout<<lastOccurence(a,n,key);
                        break;
                    }
        case 78 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                            cin>>key;
                        allOccurence(a,0,n,key);
                        break;
                    }
        case 79 :   {
                        int n,key;
                        cin>>n;
                        int a[n],b[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        int k = allStoredOccurence(a,0,n,key,b,0);
                        cout<<"Count = "<<k<<endl;
                        for(int i=0;i<k;i++)
                            cout<<b[i]<<",";
                        break;
                    }
        case 80 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        recBubbleSort(a,n,0);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 81 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        mergeSort(a,0,n-1);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 82 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cout<<inversionCount(a,0,n-1);
                        break;
                    }
        case 83 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        quickSort(a,0,n-1);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 84 :   {
                        int n;
                        cin>>n;
                        twoZeroFourEight(n);
                        break;
                    }
        case 85 :   {
                        char c[100];
                        cin>>c;
                        cout<<sti(c,strlen(c));
                        break;
                    }
        case 86 :   {
                        char c[100];
                        cin>>c;
                        pi(c,0);
                        cout<<c;
                        break;
                    }
        case 87 :   {
                        int n;
                        cin>>n;
                        cout<<tile(n);
                        break;
                    }
        case 88 :   {
                        int n,k;
                        cin>>n>>k;
                        cout<<ladder(n,k);
                        break;
                    }
        case 89 :   {
                        int n;
                        cin>>n;
                        moveHanoi(n,'A','B','C');
                        break;
                    }
        case 90 :   {
                        char in[]="abc";
                        char out[100];
                        generateSubsequence(in,out,0,0);
                        break;
                    }
        case 91 :   {
                        int n;
                        cin>>n;
                        char out[100];
                        generateBrackets(out, n,0,0,0);
                        break;
                    }
        case 92 :   {
                        int prices[]={40,20,30,100};
                        int weight[]={1,2,3,5};
                        int n=4,c=7;
                        cout<<profit(n,c,weight,prices);
                        break;
                    }
        case 93 :   {
                        char c[100];
                        cin>>c;
                        char d[100];
                        phone(c,d,0,0);
                        break;
                    }
        case 94 :   {
                        char in[100];
                        cin>>in;
                        char out[100];
                        generateStrings(in,out,0,0);
                        break;
                    }
        case 95 :   {
                        char maz[10][10]={"0000","00X0","000X","0X00"};
                        int out[10][10]={0};
                        bool ans = maze(maz,out,0,0,4,4);
                        if(ans==false)
                            cout<<"Path doesn't exist!"<<endl;
                        break;
                    }
        case 96 :   {
                        char in[100];
                        cin>>in;
                        set<string> s;
                        permute(in,0,s);
                        for(auto it:s)
                            cout<<it<<",";
                        break;
                    }
        case 97 :   {
                        int chess[10][10]={0},n;
                        cin>>n;
                        if(!nqueen(chess,n,0))
                            cout<<"Queens can't be placed"<<endl;
                        break;
                    }
        case 98 :   {
                        int sudoku[9][9]={
                             {3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0} };
                        int n=9;
                        solvesudoku(sudoku,n,0,0);
                        break;
                    }
        case 99 :   {
                        Student s[100];
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                            cin>>s[i].name>>s[i].marks;
                        bucketSort(s,n);
                        break;
                    }
        case 100 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        dnfSort(a,n);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 101 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        waveSort(a,n);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 102 :  {
                        int n;
                        cin >> n;
                        for(int i=0;i<n;i++)
                            cin >> coins[i];
                        cout << optimalGame(0,n-1);
                        break;
                    }
        case 103 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++){
                            cin>>a[i];
                        }
                        int t ;
                        cin>>t;
                        int arr[n];
                        sort(a,a+n);
                        sumitup(a,arr,t,0,n-1,0);
                        break;
                    }
        case 104 :  {
                        int n;
                        cin>>n;
                        int board[100][100]={0};
                        int count=0;
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<n;j++)
                                {
                                    cin>>board[i][j];
                                    if(board[i][j]==1)
                                        count++;
                                }
                        }
                        funkyboard(board,0,0,n,0);
                        cout<<count-ans;
                        break;
                    }
        case 105 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        printLL(head);
                        insertAtMiddle(head,0,3);
                        printLL(head);
                        insertAtTail(head,8);
                        printLL(head);
                        break;
                    }
        case 106 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        printLL(head);
                        insertAtMiddle(head,0,3);
                        printLL(head);
                        insertAtTail(head,8);
                        printLL(head);
                        deleteHead(head);
                        printLL(head);
                        deleteTail(head);
                        printLL(head);
                        deleteFromMiddle(head,3);
                        printLL(head);
                        break;
                    }
        case 107 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        if(searchKey(head,99))
                            cout<<"Found"<<endl;
                        else
                            cout<<"Not Found"<<endl;
                        break;
                    }
        case 108 :  {
                        Node* head=takeInput();
                        printLL(head);
                        break;
                    }
        case 109 :  {
                        Node* head1=NULL;
                        Node* head2=NULL;
                        cin>>head1>>head2;
                        cout<<head1<<head2;
                        break;
                    }
        case 110 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        head = recReverseLL(head);
                        printLL(head);
                        break;
                    }
        case 111 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        Node* middle = findMiddle(head);
                        cout<<middle->data<<endl;
                        break;
                    }
        case 112 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        cout<<kthNodeFromEnd(head, 3);
                        break;
                    }
        case 113 :  {
                        Node* head1=NULL;
                        Node* head2=NULL;
                        cin>>head1>>head2;
                        cout<<head1<<head2;
                        Node* m=mergeLL(head1,head2);
                        printLL(m);
                        break;
                    }
        case 114 :  {
                        Node* head=NULL;
                        cin>>head;
                        head=mergeSortLL(head);
                        printLL(head);
                        break;
                    }
        case 115 :  {
                        Node* head=NULL;
                        cin>>head;
                        if(detectCycle(head))
                            cout<<"Cycle is present"<<endl;
                        else
                            cout<<"Cycle is absent"<<endl;
                        removeCycle(head);
                        printLL(head);
                        break;
                    }
        case 116 :  {
                        Node* head=NULL;
                        insertCLL(head,20);
                        insertCLL(head,30);
                        insertCLL(head,40);
                        insertCLL(head,10);
                        printCLL(head);
                        break;
                    }
        case 117 :  {
                        Node* head=NULL;
                        insertCLL(head,20);
                        insertCLL(head,30);
                        insertCLL(head,40);
                        insertCLL(head,10);
                        printCLL(head);
                        deleteNodeCLL(head,30);
                        printCLL(head);
                        deleteNodeCLL(head,20);
                        printCLL(head);
                        break;
                    }
        case 118 :  {
                        list<pair<int,int>> *l;
                        l = new list<pair<int,int>>[3];
                        for(int i=0;i<3;i++)
                        {
                            int x,y,wt;
                            cin>>x>>y>>wt;
                            l[x].push_back(make_pair(y,wt));
                            l[y].push_back(make_pair(x,wt));
                        }
                        for(int i=0;i<3;i++)
                        {
                            cout<<"["<<i<<"]"<<" -> ";
                            for(auto xp:l[i])
                                cout<<"("<<xp.first<<","<<xp.second<<")"<<" ; "<<endl;
                        }
                        break;
                    }
        case 119 :  {
                        Node *head=NULL;
                        int n,m;
                        cin>>n>>m;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        Node *t=kReverse(head,m);;
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 120 :  {
                        Node *head=NULL;
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        Node *t = arrange_LinkedList(head);
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 121 :  {
                        Node *head=NULL;
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        arrange_LinkedListreverse(head);
                        Node* t=head;
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 122 :  {
                        Node *head=NULL;
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        insertionSortLL(head);
                        Node* t=head;
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 123 :  {
                        Stack s;
                        for(int i=0;i<5;i++)
                            s.push(i);
                        while(!s.isEmpty())
                        {
                            cout<<s.top()<<" ";
                            s.pop();
                        }
                        break;
                    }
        case 124 :  {
                        stack<int> s;
                        for(int i=0;i<5;i++)
                            s.push(i);
                        while(!s.empty())
                        {
                            cout<<s.top()<<" ";
                            s.pop();
                        }
                        break;
                    }
        case 125 :  {
                        stack<int> s;
                        for(int i=1;i<=5;i++)
                            s.push(i);
                        reverseStack(s);
                        while(!s.empty())
                        {
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                        break;
                    }
        case 126 :  {
                        stack<int> s;
                        for(int i=1;i<=5;i++)
                            s.push(i);
                        reverseStackRec(s);
                        while(!s.empty())
                        {
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                        break;
                    }
        case 127 :  {
                        char c[100]="()(()";
                        if(balancedParenthesis(c))
                            cout<<"Yes";
                        else
                            cout<<"No";
                        break;
                    }
        case 128 :  {
                        int prices[]={100,80,60,70,60,75,85};
                        int n=sizeof(prices)/sizeof(int);
                        int span[100]={0};
                        stockSpan(prices,n,span);
                        for(int i=0;i<n;i++)
                            cout<<span[i]<<" ";
                        break;
                    }
        case 129 :  {
                        int hist[] = {6, 2, 5, 4, 5, 1, 6};
                        int n = sizeof(hist)/sizeof(hist[0]);
                        cout << "Maximum area is " << getMaxArea(hist, n);
                        break;
                    }
        case 130 :  {
                        MinMaxStack s;
                        s.push(1);
                        s.push(5);
                        s.push(8);
                        s.push(10);

                        cout<<s.getMax()<<endl;
                        s.pop();
                        cout<<s.getMax()<<endl;
                        cout<<s.getMin()<<endl;

                        s.pop();
                        s.pop();
                        cout<<s.top()<<endl;
                        cout<<s.getMax()<<endl;
                        return 0;
                        break;
                    }
        case 131 :  {
                        Queue q;
                        for(int i=0;i<=6;i++)
                            q.push(i);
                        q.pop();
                        q.pop();
                        q.push(7);
                        while(!q.isEmpty())
                        {
                            cout<<q.front()<<endl;
                            q.pop();
                        }
                        break;
                    }
        case 132 :  {
                        QueueList q;
                        for(int i=0;i<5;i++)
                            q.push(i);
                        while(!q.isEmpty())
                        {
                            cout<<q.front()<<endl;
                            q.pop();
                        }
                        break;
                    }
        case 133 :  {
                        queue<int> q;
                        for(int i=1;i<10;i++)
                            q.push(i);
                        while(!q.empty())
                        {
                            cout<<q.front()<<endl;
                            q.pop();
                        }
                        break;
                    }
        case 134 :  {
                        queue<char> q;
                        char d;
                        int f[27]={0};
                        cin>>d;
                        while(d!='.')
                        {
                            q.push(d);
                            f[d-'a']++;
                            while(!q.empty())
                            {
                                int idx=q.front()-'a';
                                if(f[idx]>1)
                                    q.pop();
                                else
                                {
                                    cout<<q.front()<<endl;
                                    break;
                                }
                            }
                            if(q.empty())
                                cout<<"-1"<<endl;
                            cin>>d;
                        }
                        break;
                    }
        case 135 :  {
                        StackFromQueue s;
                        s.push(1);
                        s.push(2);
                        s.push(3);
                        while(!s.isEmpty())
                        {
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                        break;
                    }
        case 136 :  {
                        QueueFromStack q;
                        q.push(1);
                        q.push(2);
                        q.push(3);
                        q.push(4);
                        q.push(5);
                        while(!q.isEmpty())
                        {
                            cout<<q.top()<<endl;
                            q.pop();
                        }
                        break;
                    }
        case 137 :  {
                        int n,k;
                        int a[100000];
                        cin>>n;
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>k;
                        //We have to process first k elements seperately
                        deque<int> Q(k);
                        int i;
                        for(i=0;i<k;i++)
                        {
                            while(!Q.empty() &&a[i]>a[Q.back()]){
                                Q.pop_back();
                            }
                            Q.push_back(i);

                        }
                        //Process the remaining elements
                        for(;i<n;i++){
                            cout<<a[Q.front()]<<" ";
                            //1. Remove the elements which are not the part of the window(Contraction)
                            while((!Q.empty() && (Q.front()<=i-k))){
                                Q.pop_front();
                            }
                            //2. Remove the elements which are not useful and are in window
                            while(!Q.empty() && a[i]>=a[Q.back()]){
                                Q.pop_back();
                            }
                            //3. Add the new elements(Expansion)
                            Q.push_back(i);
                        }
                        cout<<a[Q.front()]<<endl;
                        break;
                    }
        case 138 :  {
                        char a[] = "babbbbb";
                        int n = strlen(a);
                        int current_len = 1, max_len = 1;
                        int visited[256]={-1};
                        visited[a[0]] = 0;
                        for(int i=1;i<n;i++){
                            int last_occ = visited[a[i]];
                            //Expansion
                            if(last_occ==-1||i-current_len>last_occ)
                                current_len += 1;
                            //Expansion + Contraction
                            else{
                                current_len = i - last_occ;
                                max_len = max(current_len,max_len);
                            }
                            visited[a[i]] = i;
                        }
                        max_len = max(current_len,max_len);
                        cout<<max_len<<endl;
                        break;
                    }
        case 139 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        int b[n]={-1};
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        stack<int> s;
                        s.push(0);
                        for(int i=1;i<n;i++)
                        {
                            while(!s.empty() && a[i]>a[s.top()])
                            {
                                b[s.top()]=i;
                                s.pop();
                            }
                            s.push(i);
                        }
                        while(!s.empty())
                        {
                            b[s.top()]=-1;
                            s.pop();
                        }
                        for(int i=0;i<n;i++)
                        {
                            if(b[i]==-1)
                                cout<<"-1"<<" ";
                            else
                                 cout<<a[b[i]]<<" ";
                        }
                        break;
                    }
        case 140 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        int b[n]={-1};
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        stack<int> s;
                        s.push(0);
                        for(int i=1;i<n;i++)
                        {
                            while(!s.empty() && a[i]>a[s.top()])
                            {
                                b[s.top()]=i;
                                s.pop();
                            }
                            s.push(i);
                        }
                        while(!s.empty())
                        {
                            b[s.top()]=-1;
                            s.pop();
                        }
                        for(int i=0;i<n;i++)
                        {
                            if(a[i]>a[n-1])
                            {
                                b[n-1]=i;
                                break;
                            }
                        }
                        for(int i=0;i<n;i++)
                        {
                            if(b[i]==-1)
                                cout<<"-1"<<" ";
                            else
                                cout<<a[b[i]]<<" ";
                        }
                        break;
                    }
        case 141 :  {
                        int n,q,a;
                        cin>>n>>q;
                        vector<stack<int> > v1;
                        vector<stack<int> > v2;
                        vector<long long int> v;
                        v.push_back(2);
                        sieve(v);
                        stack<int> s;
                        while(n--)
                        {
                            cin>>a;
                            s.push(a);
                        }
                        v1.push_back(s);
                        int i;
                        for(i=0; i<q; i++)
                        {
                            stack<int> s1,s2;
                            while(!v1[i].empty())
                            {
                                a = v1[i].top();
                                v1[i].pop();
                                if(a%v[i]==0)
                                s2.push(a);
                                else
                                s1.push(a);
                            }
                            v1.push_back(s1);
                            v2.push_back(s2);
                        }
                        for(int k=0; k<v2.size(); k++)
                        {
                            while(!v2[k].empty())
                            {
                                cout<<v2[k].top()<<endl;
                                v2[k].pop();
                            }
                        }
                        while(!v1[i].empty())
                        {
                            cout<<v1[i].top()<<endl;
                            v1[i].pop();
                        }
                        break;
                    }
        case 142 :  {
                        char c[100001];
                        cin>>c;
                        if(balancedParanthesisFull(c))
                            cout<<"Yes";
                        else
                            cout<<"No";
                        break;
                    }
        case 143 :  {
                        int t;
                        cin>>t;
                        char c[101];
                        while(t--)
                        {
                            cin>>c;
                            if(DuplicateParenthisis(c,strlen(c)))
                                cout<<"Duplicate"<<endl;
                            else
                                cout<<"Not Duplicates"<<endl;
                        }
                        break;
                    }
        case 144 :  {
                        int n,d,s=0,c;
                        cin>>n;
                        deque<int> q1;
                        deque<int> q2;
                        for(int i=0;i<n;i++)
                        {
                            cin>>d;
                            q1.push_back(d);
                        }
                        for(int i=0;i<n;i++)
                        {
                            cin>>d;
                            q2.push_back(d);
                        }
                        for(int i=0;i<n;i++)
                        {
                            c=1;
                            while(q2.front()!=q1.front())
                            {
                                c++;
                                int f=q1.front();
                                q1.pop_front();
                                q1.push_back(f);
                            }
                            if(q2.front()==q1.front())
                            {
                                q1.pop_front();
                                q2.pop_front();
                            }
                            s+=c;
                        }
                        cout<<s;
                        break;
                    }
        case 145 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1 or 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
                        cout<<endl<<"Preorder : ";
                        preorderPrint(root);    // Output : 3 4 6 5 1
                        cout<<endl<<"Postorder : ";
                        postorderPrint(root);   // Output : 6 4 1 5 3
                        cout<<endl<<"Inorder : ";
                        inorderPrint(root);     // Output : 4 6 3 1 5
                        break;
                    }
        case 146 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<endl<<"Height of Binary Tree : "<<BinaryTreeHeight(root)<<endl;
                        break;
                    }
        case 147 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        levelorderPrint(root);
                        break;
                    }
        case 148 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<"BFS Traversal : ";
                        bfs(root);
                        cout<<endl;
                        break;
                    }
        case 149 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<"BFS Traversal : ";
                        bfs2(root);
                        cout<<endl;
                        break;
                    }
        case 150 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<"No. of Nodes : "<<nodeCount(root)<<endl;
                        cout<<"Sum of Nodes : "<<nodeSum(root)<<endl;
                        break;
                    }
        case 151 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<"Diameter of Nodes : "<<diameter(root)<<endl;
                        break;
                    }
        case 152 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        PairDiameter p = fastDiameter(root);
                        cout<<"Optimized Height : "<<p.height<<endl;
                        cout<<"Optimized Diameter : "<<p.diameter<<endl;
                        break;
                    }
        case 153 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        sumReplacement(root);
                        cout<<"After Sum Replacement : ";
                        bfs2(root);
                        cout<<endl;
                        break;
                    }
        case 154 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        if(isHeightBalanced(root).balance)
                            cout<<"Balanced";
                        else
                            cout<<"Not a Balanced Tree"<<endl;
                        break;
                    }
        case 155 :  {
                        int a[]={3,2,5,6,3,7,8,3};
                        BinaryTreeNode *root1 = buildbbtreeFromArray(a,0,7);
                        cout<<"Height Balanced Binary Tree From Array : "<<endl;
                        bfs2(root1);
                        break;
                    }
        case 156 :  {
                        int in[] = {3,2,8,4,1,6,7,5};
                        int pre[] = {1,2,3,4,8,5,6,7};
                        BinaryTreeNode *root = treeFromPreIn(in,pre,0,7);
                        bfs2(root);
                        break;
                    }
        case 157 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        bfs2(root);
                        mirror(root);
                        cout<<"After Mirroring : "<<endl;
                        bfs2(root);
                        break;
                    }
        case 158 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        int maxlevel=-1;
                        cout<<"Right View : ";
                        rightView(root,0,maxlevel);
                        cout<<endl;
                        break;
                    }
        case 159 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
                        cout<<"Kth dist nodes : ";
                        BinaryTreeNode * target = root->left;
                        printAtDistK(root,target,2);
                        break;
                    }
        case 160 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
                        cout<<"LCA : "<<lca(root,1,9)->data<<endl;
                        break;
                    }
        case 161 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<"Max Sum Path : "<<maxSumPath(root).max_sum<<endl;
                        break;
                    }
         case 162 : {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
                        cout<<"Shortest Distance : "<<findDistance(root,6,1)<<endl;
                        break;
                    }
         case 163 : {
                        int a[] = {10,20,30,40,50,60,70,80,90};
                        BinaryTreeNode *root;
                        BinaryTreeNode *root1 = levelorderBuild(root,a,0,8);
                        bfs2(root1);
                        break;
                    }
         case 164 : {
                        int in[] = {3,2,8,4,1,6,7,5};
                        int pre[] = {1,2,3,4,8,5,6,7};
                        BinaryTreeNode *root = treeFromPreIn(in,pre,0,7);
                        bfs2(root);
                        break;
                    }
         case 165 : {
                        int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
                        int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
                        BinaryTreeNode *root = treeFromPostIn(in,post,0,7);
                        bfs2(root);
                        break;
                    }
         case 166 : {
                        int ino[]    = {4, 8, 10, 12, 14, 20, 22};
                        int level[] = {20, 8, 22, 4, 12, 10, 14};
                        BinaryTreeNode *root = treeFromLevelIn(ino,level,0,6,7);
                        bfs2(root);
                        break;
                    }
         case 167 : {
                        int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
                        int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
                        BinaryTreeNode *root = treeFromPrePost(pre,post,0,8);
                        bfs2(root);
                        break;
                    }
         case 168 : {
                        int pre[] = {1, 2, 4, 5, 3, 6, 7};
                        int prem[] =  {1 ,3 ,7 ,6 ,2 ,5 ,4};
                        BinaryTreeNode *root = treeFromPrePreM(pre,prem,0,6);
                        bfs2(root);
                        break;
                    }
         case 169 : {
                        string a="a+b*(c^d-e)^(f+g*h)-i";
                        infixtopostfix(a);
                        break;
                    }
         case 170 : {
                        string s="*-a/bc-/akl";
                        prefixtoinfix(s);
                        break;
                    }
        case 171 :  {
                        string s="*-a/bc-/akl";
                        prefixtopostfix(s);
                        break;
                    }
        case 172 :  {
                        string s="abc/-ak/l-*";
                        postfixtoprefix(s);
                        break;
                    }
        case 173 :  {
                        string s="ab*c+";
                        postfixtoinfix(s);
                        break;
                    }
        case 174 :  {
                        string s="(a-b/c)*(a/k-l)";
                        infixtoprefix(s);
                        break;
                    }
        case 175 :  {
                        BinaryTreeNode *bstroot = BSTbuild(); // Input : 5 3 7 1 6 8 -1
                        bfs2(bstroot);
                        break;
                    }
        case 176 :  {
                        BinaryTreeNode *bstroot = BSTbuild(); // Input : 5 3 7 1 6 8 -1
                        if(BSTSearch(bstroot,8))
                            cout<<"Present"<<endl;
                        else
                            cout<<"Absent"<<endl;
                        break;
                    }
        case 177 :  {
                        BinaryTreeNode *bstroot = BSTbuild(); // Input : 5 3 7 1 6 8 -1
                        bstroot=BSTdelete(bstroot, 5);
                        bfs(bstroot);
                        break;
                    }
        case 178 :  {
                        BinaryTreeNode *bstroot = BSTbuild(); // Input : 5 3 7 1 6 8 -1
                        if(isBST(bstroot))
                            cout<<"BST"<<endl;
                        else
                            cout<<"Not a BST"<<endl;
                        break;
                    }
        case 179 :  {
                        BinaryTreeNode *bstroot = BSTbuild(); // Input : 5 3 7 1 6 8 -1
                        BSTLL l = flatten(bstroot);
                        BinaryTreeNode *temp = l.head;
                        while(temp)
                        {
                            cout<<temp->data<<"->";
                            temp=temp->right;
                        }
                        break;
                    }
        case 180 :  {
                        int a[] = {1,2,3,4,5,6,7};
                        BinaryTreeNode *bstroot1;
                        bstroot1 = arraytoBST(bstroot1, a, 0, 6, 7);
                        bfs(bstroot1);
                        break;
                    }
        case 181 :  {
                        cout<<"No. of BSTs possible = "<<catalanNo(3);
                        break;
                    }
        case 182 :  {
                        int a[] = {10,20,30,40,50,60,70,80,90};
                        BinaryTreeNode *root;
                        BinaryTreeNode *root1 = levelorderBuild(root,a,0,8);
                        TreeBottomView(root1);
                        break;
                    }
        case 183 :  {
                        Heap h;
                        for(int i=0;i<10;i++)
                            h.push(i);
                        while(!h.isEmpty())
                        {
                            cout<<h.get()<<" ";
                            h.pop();
                        }
                        break;
                    }
        case 184 :  {
                        vector<int> v{-1,10,20,5,6,1,8,9,4};
                        buildHeap(v);
                        for(auto x:v)
                            cout<<x<<" ";
                        break;
                    }
        case 185 :  {
                        vector<int> v{-1,10,20,5,6,1,8,9,4};
                        buildHeapFast(v);
                        for(auto x:v)
                            cout<<x<<" ";
                        break;
                    }
        case 186 :  {
                        vector<int> v{-1,10,20,5,6,1,8,9,4};
                        heapSort(v);
                        for(auto x:v)
                            cout<<x<<" ";
                        break;
                    }
        case 187 :  {
                        priority_queue<int> pmax; //by default maxHeap
                        priority_queue<int, vector<int>, greater<int>> p; //for minimum
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            p.push(d);
                        }
                        while(!p.empty())
                        {
                            cout<<p.top()<<" ";
                            p.pop();
                        }
                        break;
                    }
        case 188 :  {
                        priority_queue<Person, vector<Person>, Personcompare> pq;
                        Person p("A",12);
                        pq.push(p);
                        Person p1("B",99);
                        pq.push(p1);
                        Person p2("C",0);
                        pq.push(p2);
                        Person p3("D",9);
                        pq.push(p3);
                        Person p4("E",48);
                        pq.push(p4);
                        for(int i=0;i<3;i++)
                        {
                            Person p = pq.top();
                            cout<<p.name<<" "<<p.age<<endl;
                            pq.pop();
                        }
                        break;
                    }
        case 189 :  {
                        int r[]={4,3,2,6};
                        cout<<joinRopes(r,4)<<endl;
                        break;
                    }
        case 190 :  {

                        break;
                    }
        case 191 :  {
                        vector<vector<int>> v{{2,5,7,8},{2,7,8,9,9},{9,9,9,10},{10,27,344,443}};
                        vector<int> res = mergeKsortedArrays(v);
                        for(auto x:res)
                            cout<<x<<" ";
                        break;
                    }
        case 192 :  {
                        //11 16 21 25 26 30 31 33 34 36 38 40 41 46 49 50
                        int mat[4][4]= {{11, 21, 31, 41},{16, 26, 36, 46},{25, 30, 38, 49},{33, 34, 40, 50}};
                        cout<<kthSmallest(mat,4,12);
                        break;
                    }
        case 193 :  {
                        //11 16 21 25 26 30 31 33 34 36 38 40 41 46 49 50
                        int mat[4][4]= {{11, 21, 31, 41},{16, 26, 36, 46},{25, 30, 38, 49},{33, 34, 40, 50}};
                        cout<<kthSmallestOptimised(mat,4,12);
                        break;
                    }
        case 194 :  {
                        ll n,k,d;
                        cin>>n>>k;
                        priority_queue<ll> pq;
                        for(int i=0;i<n;i++)
                        {
                            cin>>d;
                            if(d==1)
                            {
                                ll a,b;
                                cin>>a>>b;
                                ll c=pow(a,2)+pow(b,2);
                                if(i>=k)
                                {
                                    if(pq.top()>c)
                                    {
                                        pq.pop();
                                        pq.push(c);
                                    }
                                }
                                else
                                    pq.push(c);
                            }
                            else
                                cout<<pq.top()<<endl;
                        }
                        break;
                    }
        case 195 :  {
                        //Input :
                        //1
                        //5 2
                        //5 1 3 5 2
                        //Output :
                        //5
                        //1 5
                        //1 3
                        //5 1
                        //5 1
                        int t;int n,k;
                        cin>>t;
                        int *arr;
                        while(t--)
                        {
                         priority_queue<abc,vector<abc>,functor>pq;
                         //Preparing a priority queue of abc type(ie. based on the number and on the frequency)
                         cin>>n>>k;
                         arr=new int[n];int nn;
                         int count[100]={0};
                         //To maintain frequency count of each number
                         for(int i=0;i<n;i++)
                            cin>>arr[i];
                         for(int i=0;i<n;i++)
                         {
                             count[arr[i]]++;
                             nn=k;
                             for(int j=0;j<=i;j++)
                             {
                                abc y(count[arr[j]],arr[j]);
                                pq.push(y);//Pushing an object of class abc(containg the number and its frequency) to the heap
                             }
                             while(!pq.empty()&&nn--)
                             {
                                 abc yy=pq.top();
                                 cout<<yy.num<<" ";//brignging
                                 int l1=yy.freq;
                                 while(l1--)//Emptying the heap
                                    pq.pop();
                             }
                             while(!pq.empty())
                                pq.pop();
                         }
                         cout<<endl;
                        }
                        break;
                    }
        case 196 :  {
                        int k = 4;
                        int arr[] = { 5, 2, 1, 3, 2 };
                        int n = sizeof(arr) / sizeof(arr[0]);
                        kTop(arr, n, k);
                        break;
                    }
        case 197 :  {
                        Hashtable price_menu;
                        price_menu.insert("Burger", 125);
                        price_menu.insert("Pizza", 151);
                        price_menu.insert("Water", 10);
                        price_menu.insert("Hot Water", 12);
                        price_menu.insert("Chicken Tikka", 203);
                        price_menu.insert("Biriyani", 357);
                        price_menu.insert("Mandi", 409);
                        price_menu.print();

                        int* price = price_menu.search("Burger");
                        if(price!=NULL)
                            cout<<"Burger Price = "<<*price<<endl;
                        else
                            cout<<"Not found in the menu"<<endl;

                        price_menu.erase("Biriyani");
                        price_menu.print();

                        //Easy access using [] operator
                        //Insert
                        price_menu["Dosa"]=60;
                        //print
                        cout<<"Price of Dosa = "<<price_menu["Dosa"]<<endl;
                        //Update
                        price_menu["Dosa"] += 10;
                        //Search
                        cout<<"Price of Dosa = "<<price_menu["Dosa"]<<endl;
                        break;
                    }
        case 198 :  {
                        map<string,int> m;
                        //1. Insert
                        m.insert(make_pair("Mango",100));
                        pair<string,int> p;
                        p.first = "Apple";
                        p.second = 120;
                        m.insert(p);
                        m["Banana"] = 20;
                        //2. Search
                        string fruit;
                        cin>>fruit;
                        //update the price
                        m[fruit] += 22;
                        auto it = m.find(fruit);
                        if(it!=m.end())
                            cout<<"price of "<<fruit<<" is"<<m[fruit]<<endl;
                        else
                            cout<<"fruit is not present "<<endl;
                        //3. Erase
                        m.erase(fruit);
                        //another way to find a particular map
                        // it stores unique keys only once
                        if(m.count(fruit))
                            cout<<"Price is "<<m[fruit]<<endl;
                        else
                            cout<<"Couldnt find "<<endl;

                        m["Litchi"] = 60;
                        m["Pineapple"] = 80;
                        //Iterate over all the key value pairs
                        for(auto it=m.begin();it!=m.end();it++)
                            cout<<it->first<<" and "<<it->second<<endl;

                        //for each loop
                        for(auto p:m)
                            cout<<p.first<<" : "<<p.second<<endl;
                        break;
                    }
        case 199 :  {
                        unordered_map<StudentMap, int, HashFn> m; //HashFn class for comparing same as we did in priority queue

                        StudentMap s1("Haseeb","Rahman","10");
                        StudentMap s2("Kunal","Sharma","11");
                        StudentMap s3("Haseeb","Rahman","12");
                        StudentMap s4("Aman","Rao","12");
                        StudentMap s5("Haseeb","Rahman","10");

                        //Insert
                        m[s1]=10;
                        m[s2]=11;
                        m[s3]=87;
                        m[s4]=90;
                        m[s5]=100;

                        //Iterate
                        for(auto x:m)
                            cout<<x.first.fname<<" : "<<x.second<<endl;

                        //Access
                        cout<<endl<<"S3 marks = "<<m[s3]<<endl;
                        break;
                    }
        case 200 :  {
                        unordered_map<string, vector<string>> phonebook;
                        phonebook["haseeb"].push_back("100");
                        phonebook["haseeb"].push_back("200");
                        phonebook["haseeb"].push_back("300");
                        phonebook["haseeb"].push_back("400");
                        phonebook["aman"].push_back("500");
                        phonebook["aman"].push_back("600");
                        phonebook["aman"].push_back("700");
                        phonebook["aman"].push_back("800");

                        //Iterate
                        for(auto p:phonebook)
                        {
                            cout<<"Name = "<<p.first<<" -> ";
                            for(string s:p.second)
                                cout<<s<<",";
                            cout<<endl;
                        }

                        //Search and Print
                        string name;
                        cin>>name;
                        if(phonebook.count(name)==0)
                            cout<<"Absent!";
                        else
                        {
                            for(auto s:phonebook[name])
                                cout<<s<<",";
                        }
                        break;
                    }
        case 201 :  {
                        BinaryTreeNode* root = preorderBuild(); //Input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1 or 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
                        map<int, vector<int>> m;
                        int d=0;
                        verticalOrderPrint(root,d,m);
                        for(auto x:m)
                        {
                            cout<<x.first<<"->";
                            for(auto y:x.second)
                                cout<<y<<",";
                            cout<<endl;
                        }
                        break;
                    }
        case 202 :  {
                        int a[]={6,-1,2,1,-1};
                        if(checkZeroSum(a,5))
                            cout<<"Present!"<<endl;
                        else
                            cout<<"Absent!"<<endl;
                        break;
                    }
        case 203 :  {
                        int a[]={0,-1,1,2,5,-5,-2};
                        cout<<longestSubarrayZeroSum(a,7)<<endl;
                        break;
                    }
        case 204 :  {
                        int a[]={1,-1,5,-2,3};
                        cout<<longestSubarrayKSum(a,5,3)<<endl;
                        break;
                    }
        case 205 :  {
                        int a[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17};
                        cout<<largestConSubseq(a,15)<<endl;
                        break;
                    }
        case 206 :  {
                        int a[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17};
                        cout<<largestConSubseq2(a,15)<<endl;
                        break;
                    }
        case 207 :  {
                        string s="hllloeaeo World";
                        string p="eelo";
                        cout<<findMinWindow(s,p)<<endl;
                        break;
                    }
        case 208 :  {
                        int a[][2]={{ 1, 2 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 2 }};
                        cout<<rightAngledTriangles(a,5)<<endl;
                        break;
                    }
        case 209 :  {
                        int m;
                        cin>>m; // Input : 8 00 01 11 10 21 20 31 30
                        vector<Point> cord;
                        while(m--)
                        {
                            int x,y;
                            cin>>x>>y;
                            Point p(x,y);
                            cord.push_back(p);
                        }
                        cout<<countRects(cord); // Output : 6
                        break;
                    }
        case 210 :  {
                        Trie t;
                        char words[][100]={"a","hello","not","news","apple"};
                        for(int i=0;i<5;i++)
                            t.insert(words[i]);
                        char m[]="not";
                        if(t.find(m))
                            cout<<"Present"<<endl;
                        else
                            cout<<"Absent"<<endl;
                        break;
                    }
        case 211 :  {
                        TrieUnique t;
                        char words[][100]={"cobra", "zebraah", "dog", "zebra", "dove", "duck"};
                        for(int i=0;i<6;i++)
                            t.insert(words[i]);
                        for(int i=0;i<6;i++)
                            t.printCount(words[i]);
                        for(int i=0;i<6;i++)
                            t.print(words[i]);
                        break;
                    }
        case 212 :  {
                        int a[]={3,10,5,25,2,8};
                        TrieXor t;
                        cout<<t.maxXor(a,6)<<endl;
                        break;
                    }
        case 213 :  {
                        int N,n,k;
                        cin>>n>>k;
                        int a[n];N=n;
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        unordered_map<int,int> m;
                        for(int i=0;i<n;i++)
                            m[a[i]]=i;
                        while(k)
                        {
                            int best_pos=N-n;
                            if(best_pos == m[n])
                            {
                                bool sorted = IsSorted(a,N);
                                if(sorted){
                                    break;
                                }
                                n--;
                                continue;
                            }
                            else
                            {
                                int wrong_no = a[best_pos];
                                int n_index = m[n];
                                swap(a[n_index],a[best_pos]);
                                m[wrong_no]=n_index;
                                m[n]=best_pos;
                                k--;
                                n--;
                            }
                        }
                        for(int i=0;i<N;i++)
                            cout<<a[i]<<" ";
                        break;
                    }
        case 214 :  {
                        int t;
                        cin>>t;
                        while(t--)
                        {
                            int n,d,q;
                            cin>>n;
                            unordered_map<int,bool> m;
                            while(n--)
                            {
                                cin>>d;
                                m[d]=true;
                            }
                            cin>>q;
                            while(q--)
                            {
                                cin>>d;
                                if(m[d])
                                    cout<<"Yes"<<endl;
                                else
                                    cout<<"No"<<endl;
                            }
                            m.clear();
                        }
                        break;
                    }
        case 215 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];

                        vector<int> v;
                        hashFn215(a,n,m215,v);
                        sort(v.begin(),v.end(),compe);
                        for(auto x : v)
                            cout<<x<<endl;
                        break;
                    }
        case 216 :  {
                        int n,ans=0,j=0;
                        cin>>n;
                        int a[n];
                        unordered_map<int,int> m;
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        for(int i=0;i<n;i++)
                        {
                            while(j<n && m.find(a[j])==m.end())
                            {
                                m[a[j]]++;
                                j++;
                            }
                            ans += (j-i)*(j-i+1)/2;
                            m.erase(a[i]);
                        }
                        cout<<ans;
                        break;
                    }
        case 217 :  {
                        TrieDict t;
                        int n,q;
                        cin>>n;
                        char word[1000000];
                        for(int i=0;i<n;i++)
                        {
                            cin>>word;
                            t.insert(word);
                        }
                        cin>>q;
                        char sword[1001];
                        for(int i=0;i<q;i++)
                        {
                            cin>>sword;
                            vector<string> v;
                            if(!t.search(sword, v))
                            {
                                cout<<"No suggestions\n";
                                continue;
                            }
                            sort(v.begin(),v.end());
                            for(auto x:v)
                                cout<<x<<endl;
                            v.clear();
                        }
                        break;
                    }
        case 218 :  {
                        /*
                        class trieNode {

                        public:
                            trieNode *left; /// represents 0
                            trieNode *right; /// represent one
                            vector<int> v;
                        };

                        void insert(int n, trieNode *head, int index) {

                            trieNode *curr = head;
                            for (int i = 31; i >= 0; i--) {

                                int bit = (n >> i) & 1;
                                if (bit == 0) {

                                    if (curr->left == NULL) {
                                        curr->left = new trieNode();
                                    }
                                    curr->v.push_back(index);
                                    curr = curr->left;
                                }
                                /// bit is one ..
                                else {

                                    if (curr->right == NULL) {
                                        curr->right = new trieNode();
                                    }
                                    curr->v.push_back(index);
                                    curr = curr->right;
                                }
                            }
                            curr->v.push_back(index);
                        }

                        bool binarysearchrange(vector<int>v, int left , int right) {
                            int l = 0;
                            int h = v.size() - 1;
                            while (l <= h) {

                                int m = (l + h) / 2;
                                int val = v[m];
                                if (val >= left && val <= right) {
                                    return true;
                                }
                                else if (val < left) {
                                    l = m + 1;
                                }
                                else if (val > right) {
                                    h = m - 1;
                                }

                            }
                            return false;
                        }

                        int findmaxorpair(trieNode *head, int el, int left, int right) {
                            trieNode *curr = head;
                            int value = el;
                            int curr_xor = 0;
                            for (int j = 31; j >= 0; j--) {

                                int b = (value >> j) & 1;
                                if (b == 0) {

                                    if (curr->right != NULL && binarysearchrange(curr->right->v, left, right)) {
                                        curr = curr->right;
                                        curr_xor += (int)pow(2, j);
                                    }
                                    else {
                                        curr = curr->left;
                                    }
                                }
                                else {
                                    if (curr->left != NULL && binarysearchrange(curr->left->v, left, right)) {
                                        curr = curr->left;
                                    }
                                    else {
                                        curr_xor += (int)pow(2, j); //Here
                                        curr = curr->right;
                                    }
                                }
                            }
                            return curr_xor;
                        }

                        int main() {
                            trieNode *myt = new trieNode();
                            int t;
                            cin >> t;
                            int index = 0;
                            while (t--) {

                                int q;
                                cin >> q;

                                if (q == 0) {
                                    int val;
                                    cin >> val;
                                    insert(val, myt, index);
                                    index++;
                                }
                                else if (q == 1) {
                                    int x, l, r;
                                    cin >> l >> r >> x; //Here
                                    cout << findmaxorpair(myt, x, l - 1, r - 1)<<endl;
                                }
                            }
                            return 0;
                        }
                        */
                        break;
                    }
        case 219 :  {
                        /*
                        #include <bits/stdc++.h>
                        using namespace std ;

                        class node {
                        public :
                            node *left ;
                            node *right ;
                            node(){
                                left = right = NULL ;
                            }
                        };

                        class Trie {
                            node *root ;
                        public :
                            Trie(){
                                root = new node() ;
                            }
                            void insert(int n){
                                node *temp = root ;
                                for(int i=31 ;i>=0;i--){
                                    int bit = (n >> i) & 1;
                                    if(bit == 0){
                                        if(temp->left == NULL)
                                            temp->left = new node() ;
                                        temp = temp->left ;
                                    }
                                    else {
                                        if(temp->right == NULL)
                                            temp->right = new node() ;
                                        temp = temp->right ;
                                    }
                                }
                            }
                            int findMaxXorPair(int value){
                                node *temp = root ;
                                int currentXor = 0 ;
                                for(int j=31 ;j>=0 ; j--){
                                    int bit = (value >> j) & 1;
                                    if(bit == 0){
                                        if(temp->right != NULL){
                                            temp = temp->right ;
                                            currentXor += (1<<j);
                                        }
                                        else
                                            temp = temp->left ;
                                    }
                                    else {
                                        if(temp->left != NULL){
                                            temp = temp->left ;
                                            currentXor += (1<<j);
                                        }
                                        else
                                            temp = temp->right ;
                                    }
                                }
                                return currentXor ;
                            }
                        };

                        int main() {
                            int n ;
                            cin >> n;
                            int result = 0, arr[n], lbest[100000], rbest[100000], left_value = 0,right_value = 0;

                            Trie tl;
                            tl.insert(0);
                            for(int i=0;i<n;i++){
                                cin >> arr[i] ;
                                left_value ^= arr[i];
                                lbest[i] = max( (i == 0)? 0 : lbest[i-1] , tl.findMaxXorPair(left_value));
                                tl.insert(left_value);
                            }

                            Trie tr ;
                            tr.insert(0);
                            for(int i=n-1;i>=0;i--){
                                right_value ^= arr[i];
                                rbest[i] = max((i == n - 1) ? 0 : rbest[i + 1],tr.findMaxXorPair(right_value));
                                tr.insert(right_value);
                                int val = rbest[i] + (i == 0 ? 0 : lbest[i - 1]);
                                result = max(result,val);
                            }
                            cout << result ;
                            return 0 ;
                        }
                        */
                        break;
                    }
        case 220 :  {
                        int a[]={1,2,5,10,20};
                        cout<<indianCoinGreedy(a,5,39)<<endl;
                        break;
                    }
        case 221 :  {
                        /*
                        Input :
                        6
                        7 9
                        0 10
                        4 5
                        8 9
                        4 10
                        5 7
                        */
                        int n,s,e;
                        cin>>n;
                        vector<pair<int,int>> v;
                        for(int i=0;i<n;i++)
                        {
                            cin>>s>>e;
                            v.push_back(make_pair(s,e));
                        }
                        sort(v.begin(),v.end(),compBusyMan);
                        int c=1;
                        int finish = v[0].second;
                        for(int i=1;i<n;i++)
                        {
                            if(v[i].first>=finish)
                            {
                                c++;
                                finish = v[i].second;
                            }
                        }
                        cout<<c<<endl; // Output : 3
                        break;
                    }
        case 222 :  {
                        int n,d,ans=0;
                        cin>>n;
                        vector<int> white,black;
                        for(int i=0;i<n/2;i++)
                        {
                            cin>>d;
                            white.push_back(d);
                        }
                        for(int i=0;i<n/2;i++)
                        {
                            cin>>d;
                            black.push_back(d);
                        }
                        sort(white.begin(),white.end());
                        sort(black.begin(),black.end());
                        for(int i=0;i<n/2;i++)
                            ans += black[i]-white[i];
                        cout<<ans<<endl;
                        break;
                    }
        case 223 :  {
                        /*
                        Input :
                        7
                        a 1
                        b 2
                        c 2
                        d 1
                        e 5
                        f 7
                        g 7
                        */
                        int n,d,ans=0,badness=0;
                        cin>>n;
                        string s;
                        int a[n+1]={0};
                        for(int i=0;i<n;i++)
                        {
                            cin>>s>>d;
                            a[d]++;
                        }
                        int avail_rank = 1;
                        for(int i=1;i<=n;i++)
                        {
                            while(a[i])
                            {
                                badness = abs(avail_rank - i);
                                ans += badness;
                                a[i]--;
                                avail_rank++;
                            }
                        }
                        cout<<ans<<endl; // Output : 5
                        break;
                    }
        case 224 :  {
                        /* Input :
                        4
                        0 6 10 0
                        */
                        int n, max_load=0, load=0, diff=0;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                        {
                            cin>>a[i];
                            load += a[i];
                        }
                        if(load%n!=0)
                        {
                            cout<<"-1"<<endl;
                            return 0;
                        }
                        load /= n;
                        for(int i=0;i<n;i++)
                        {
                            diff += a[i]-load;
                            int ans = max(diff,-diff);
                            max_load = max(max_load,ans);
                        }
                        cout<<max_load; // Output : 4
                        break;
                    }
        case 225 :  {
                        /* Input :
                        15 8 3
                        3 8
                        11 2
                        8 6
                        */
                        int w,h,n;
                        cin>>w>>h>>n;
                        int x[100],y[100];
                        for(int i=0;i<n;i++)
                            cin>>x[i]>>y[i];
                        sort(x,x+n);sort(y,y+n);
                        int dx = x[0]-1;
                        int dy = y[0]-1;
                        for(int i=1;i<n;i++)
                        {
                            dx = max(dx, x[i]-x[i-1]-1);
                            dy = max(dy, y[i]-y[i-1]-1);
                        }
                        // corner case when the grid is ending
                        dx = max(dx, w-x[n-1]);
                        dy = max(dy, h-y[n-1]);
                        cout<<dx*dy<<endl; // Output : 12
                        break;
                    }
        case 226 :  {
                        int n,d,c=0;
                        cin>>n>>d;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        sort(a,a+n);
                        int i=0;
                        while(i<n-1)
                        {
                            if(a[i+1]-a[i]<=d)
                            {
                                i=i+2;
                                c++;
                            }
                            else
                                i++;
                        }
                        cout<<c;
                        break;
                    }
        case 227 :  {
                        /* Input :
                        1
                        4
                        4 4
                        5 2
                        11 5
                        15 10
                        25 10
                        */
                        int n,t,x,d,f,D,F,prev,flag=0,ans=0;
                        cin>>t;
                        while(t--)
                        {
                            vector<pair<int,int>> v;
                            priority_queue<int> pq;
                            cin>>n;
                            for(int i=0;i<n;i++)
                            {
                                cin>>d>>f;
                                v.push_back(make_pair(d,f)); // 4,4 5,2 11,5 15,10
                            }
                            cin>>D>>F;
                            sort(v.begin(),v.end(),compExp); // 15,10 11,5 5,2 4,4
                            for(int i=0;i<n;i++)
                                v[i].first = D-v[i].first; // 10,10 14,5 20,2 21,4

                            x=0; // current city
                            prev=0; // the prev city we have visited

                            while(x<n)
                            {
                                if(F >= (v[x].first-prev))
                                {
                                    F -= (v[x].first-prev);
                                    pq.push(v[x].second);
                                    prev = v[x].first;
                                }
                                else
                                {
                                    if(pq.empty())
                                    {
                                        flag=1;
                                        break;
                                    }
                                    F += pq.top();
                                    pq.pop();
                                    ans++;
                                    continue;
                                }
                                x++;
                            }
                            if(flag==1)
                            {
                                cout<<"-1"<<endl;
                                continue;
                            }
                            D = D - v[n-1].first;
                            if(F>=D)
                            {
                                cout<<ans<<endl;
                                continue;
                            }
                            if(F<D)
                            {
                                if(pq.empty())
                                {
                                    flag=1;
                                    break;
                                }
                                F += pq.top();
                                pq.pop();
                                ans++;
                            }
                            if(flag==1)
                            {
                                cout<<"-1"<<endl;
                                continue;
                            }
                            cout<<ans<<endl; // Output : 2
                        }
                        break;
                    }
        case 228 :  {
                        /* Input :
                        3 50
                        60 10
                        100 20
                        120 30
                        */
                        int n,w,profit,weight;
                        cin>>n>>w;
                        vector<pair<int,int>> v;
                        for(int i=0;i<n;i++)
                        {
                            cin>>profit>>weight;
                            v.push_back(make_pair(profit,weight));
                        }
                        sort(v.begin(),v.end(),compKnapsackGreedy);
                        int curr_weight=0, i=0;
                        float total_profit=0.0;
                        while(curr_weight + v[i].second <= w)
                        {
                            curr_weight += v[i].second;
                            total_profit += v[i].first;
                            i++;
                        }
                        if(curr_weight != w)
                        {
                            int remain = w-curr_weight;
                            float fraction = remain/(v[i].second*1.0);
                            total_profit += (v[i].first*fraction*1.0);
                        }
                        cout<<total_profit<<endl; // Output : 240
                        break;
                    }
        case 229 :  {
                        char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
                        int freq[] = { 5, 9, 12, 13, 16, 45 };
                        int size = sizeof(data) / sizeof(data[0]);
                        HuffmanCodes(data, freq, size);
                        break;
                    }
        case 230 :  {
                        int t;
                        cin>>t;
                        while(t--)
                        {
                            long long int n;
                            cin>>n;
                            long long int c[n],l[n];
                            for(long long int i=0;i<n;i++)
                                cin>>c[i];
                            for(long long int i=0;i<n;i++)
                                cin>>l[i];
                            long long int min_cost = c[0];
                            long long int next_stop = l[0];
                            long long int ans = min_cost*next_stop;
                            for(long long int i=1;i<n;i++)
                            {
                                if(c[i]<min_cost)
                                    min_cost = c[i];
                                ans += min_cost * l[i];
                            }
                            cout<<ans<<endl;
                        }
                        break;
                    }
        case 231 :  {
                        int t;
                        cin>>t;
                        while(t--)
                        {
                            long long int n;
                            cin>>n;
                            long long int a[n];
                            for(long long int i=0;i<n;i++)
                                cin>>a[i];
                            sort(a,a+n);
                            long long int min=0,max=0;
                            for(int i=0;i<n/2;i++)
                            {
                                max += abs(a[i]-a[n-i-1]);
                                min += abs(a[2*i]-a[2*i+1]);
                            }
                            cout<<min<<" "<<max<<endl;
                        }
                        break;
                    }
        case 232 :  {
                        cout<<fibrec(5)<<endl;
                        break;
                    }
        case 233 :  {
                        int dp[100]={0};
                        cout<<fibTopDown(6,dp)<<endl;
                        break;
                    }
        case 234 :  {
                        cout<<fibBottomUp(7)<<endl;
                        break;
                    }
        case 235 :  {
                        cout<<fibBottomUpOpt(12)<<endl;
                        break;
                    }
        case 236 :  {
                        int dp[100]={0};
                        cout<<minStepsTopDown(10,dp);
                        break;
                    }
        case 237 :  {
                        cout<<minStepsBottomUp(10);
                        break;
                    }
        case 238 :  {
                        int coins[] = {1,7,10};
                        int dp[100]={0};
                        int T=3; // different types of coins
                        cout<<minCoinsTopDown(15,coins,T,dp);
                        break;
                    }
        case 239 :  {
                        int coins[] = {1,3,5};
                        int T=3; // different types of coins
                        cout<<minCoinsBottomUp(8,coins,T);
                        break;
                    }
        case 240 :  {
                        int p[]={2,3,5,1,4};
                        int dp[100][100]={0};
                        cout<<winesProbTopDown(p,0,4,1,dp);
                        break;
                    }
        case 241 :  {
                        int a[]={2,3,5,1,4};
                        cout<<winesProbBottomUp(a,5);
                        break;
                    }
        case 242 :  {
                        int a[]={-3,2,5,-1,6,3,-2,7,-5,2};
                        cout<<maxSubarraySumDp(a,10);
                        break;
                    }
        case 243 :  {
                        int n=4,k=3;
                        int dp[100]={0};
                        cout<<laddersTopDown(n,k,dp);
                        break;
                    }
        case 244 :  {
                        int n=4,k=3;
                        cout<<laddersBottomUp(n,k);
                        break;
                    }
        case 245 :  {
                        int n=4,k=3;
                        cout<<laddersBottomUpOpt(n,k);
                        break;
                    }
        case 246 :  {
                        int prices[] = {1,5,8,9,10,17,17,20};
                        cout<<rodCutting(prices,8);
                        break;
                    }
        case 247 :  {
                        int prices[] = {1,5,8,9,10,17,17,20};
                        int dp[100]={0};
                        cout<<rodCuttingTopDown(prices,8,dp);
                        break;
                    }
        case 248 :  {
                        int prices[] = {1,5,8,9,10,17,17,20};
                        cout<<rodCuttingBottomUp(prices,8);
                        break;
                    }
        case 249 :  {
                        string s1 = "ABCD";
                        string s2 = "ABEDG";
                        cout<<lcs(s1,s2,0,0);
                        break;
                    }
        case 250 :  {
                        string s1 = "ABCD";
                        string s2 = "ABEDG";
                        int n1=s1.length(), n2=s2.length();
                        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1)); //n1+1 and n2+1 to see the visited cells
                        cout<<lcsTopDown(s1,s2,0,0,dp);
                        cout<<endl;
                        for(int i=0;i<n1+1;i++)
                        {
                            for(int j=0;j<n2+1;j++)
                                cout<<dp[i][j]<<" ";
                            cout<<endl;
                        }
                        break;
                    }
        case 251 :  {
                        string s1 = "ABCD";
                        string s2 = "ABEDG";
                        cout<<lcsBottomUp(s1,s2);
                        break;
                    }
        case 252 :  {
                        int a[] = {1,5,2,3,4,9,6,10};
                        cout<<lisDP(a,8);
                        break;
                    }
        case 253 :  {
                        int a[] = {1,5,2,3,4,9,6,10};
                        cout<<lis2(a,8);
                        break;
                    }
        case 254 :  {
                        int a[] = {1,5,2,3,4,9,6,10};
                        cout<<lis3(a,8);
                        break;
                    }
        case 255 :  {
                        int a[] = {4,2,3,1,3};
                        cout<< MatrixChainOrder(a,5);
                        break;
                    }
        case 256 :  {
                        int n,x,y,z;
                        cin>>n>>x>>y>>z;// 5 2 1 3
                        cout<<cellMitosis(n,x,y,z);// 4
                        break;
                    }
        case 257 :  {
                        int a[100], dp[100][100];
                        int n;
                        while((scanf("%d",&n)!=EOF))
                        {
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            for(int i=0;i<=n;i++)
                            {
                                for(int j=0;j<=n;j++)
                                    dp[i][j]=-1;
                            }
                            cout<<solveMixtures(0,n-1,a,dp)<<endl;
                        }
                        // 2
                        // 18 19
                        // Output : 342
                        break;
                    }
        case 258 :  {
                        int n=4;
                        cout<<friendsPairing(n);
                        break;
                    }
        case 259 :  {
                        int n;
                        cin >> n;
                        int coins[n];
                        for(int i=0;i<n;i++)
                            cin>>coins[i];
                        int dp[100][100];
                        memset(dp,-1,sizeof(dp));
                        cout<<optimalGameDP(0,n-1,coins,dp);
                        break;
                    }
        case 260 :  {
                        int r,c;
                        cin>>r>>c;
                        int a[100][100];
                        for(int i=0;i<r;i++)
                        {
                            for(int j=0;j<c;j++)
                                cin>>a[i][j];
                        }
                        cout<<minCostPath(r,c,a);
                        break;
                    }
        case 261 :  {
                        int dp[100][100];
                        memset(dp,0,sizeof(dp));
                        int m,n,p;
                        cin>>m>>n>>p;
                        for(int i=0;i<p;i++)
                        {
                            int x,y;
                            cin>>x>>y;
                            dp[x-1][y-1]={-1};
                        }
                        cout<<robotDP(m,n,dp);
                        break;
                        // Input : 4 3 2
                        //3 3
                        //3 1
                        //Output : 2
                    }
        case 262 :  {
                        int a[] = { -3, 8, -2, 1, -6 };
                        int n = sizeof(a) / sizeof(a[0]);
                        int x = -1;
                        cout << getMaximumSum(a, n, x);
                        break;
                    }
        case 263 :  {
                        long long int n;
                        cin>>n;
                        cout<<binaryString(n)<<endl;
                        break;
                    }
        case 264 :  {
                        int n;
                        cin>>n;
                        cout<<fibMatrixExp(n)<<endl;
                        break;
                    }
        case 265 :  {
                        int n,s;
                        cin>>n>>s;
                        int w[n],p[n];
                        for(int i=0;i<n;i++)
                            cin>>w[i];
                        for(int i=0;i<n;i++)
                            cin>>p[i];
                        int dp[11][11]; //dp[n][s+1]
                        memset(dp,-1,sizeof(dp));
                        cout<<knapsackTopDownDP(s,w,p,dp,n-1);
                        break;
                    }
        case 266 :  {
                        int n,s;
                        cin>>n>>s;
                        int w[n],p[n];
                        for(int i=0;i<n;i++)
                            cin>>w[i];
                        for(int i=0;i<n;i++)
                            cin>>p[i];
                        cout<<knapsackBottomUpDP(s,n,w,p);
                        break;
                    }
        case 267 :  {
                        ll n,c;
                        cin>>n>>c;
                        ll s[n],p[n];
                        for(ll i=0;i<n;i++)
                            cin>>s[i];
                        for(ll i=0;i<n;i++)
                            cin>>p[i];
                        cout<<zeronKnapsack(s,p,n,c);
                        break;
                    }
        case 268 :  {
                        string s1,s2,s3;
                        cin>>s1>>s2>>s3;
                        cout<<lcs3(s1,s2,s3);
                        break;
                    }
        case 269 :  {
                        /*
                        #include<stdio.h>
                        #include<string.h>
                        int max (int x, int y) { return (x > y)? x : y; }

                        int lps(char *str)
                        {
                        int n = strlen(str);
                        int i, j, cl;
                        int L[n][n];

                        for (i = 0; i < n; i++)
                            L[i][i] = 1;
                            for (cl=2; cl<=n; cl++)
                            {
                                for (i=0; i<n-cl+1; i++)
                                {
                                    j = i+cl-1;
                                    if (str[i] == str[j] && cl == 2)
                                    L[i][j] = 2;
                                    else if (str[i] == str[j])
                                    L[i][j] = L[i+1][j-1] + 2;
                                    else
                                    L[i][j] = max(L[i][j-1], L[i+1][j]);
                                }
                            }

                            return L[0][n-1];
                        }
                        int main()
                        {
                            char seq[] = "GEEKS FOR GEEKS";
                            int n = strlen(seq);
                            printf ("The length of the LPS is %d", lps(seq));
                            getchar();
                            return 0;
                        }
                        */
                        break;
                    }
        case 270 :  {
                        /*
                        class Graph
                        {
                            int v;
                            list<int> *l;

                            public:
                            Graph(int v)
                            {
                                this->v = v;
                                l = new list<int>[v];
                            }

                            void addEdge(int x, int y)
                            {
                                l[x].push_back(y);
                                l[y].push_back(x);
                            }

                            void printGraph()
                            {
                                for(int i=0;i<v;i++)
                                {
                                    cout<<i<<" -> ";
                                    for(auto y:l[i])
                                        cout<<y<<",";
                                    cout<<endl;
                                }
                            }
                        };

                        int main()
                        {
                            Graph g(4);
                            g.addEdge(0,1);
                            g.addEdge(0,2);
                            g.addEdge(2,3);
                            g.addEdge(1,2);
                            g.printGraph();
                            return 0;
                        }
                        */
                        break;
                    }
        case 271 :  {
                        /*
                        class Graph
                        {
                            map<string,list<pair<string,int>>> l;

                            public:
                            void addEdge(string a, string b, bool bidr, int n)
                            {
                                l[a].push_back(make_pair(b,n));
                                if(bidr)
                                    l[b].push_back(make_pair(a,n));
                            }

                            void print()
                            {
                                for(auto p:l)
                                {
                                    cout<<p.first<<"--->";
                                    list<pair<string,int>> nbrs = p.second;
                                    for(auto nbr : nbrs)
                                        cout<<nbr.first<< " " <<nbr.second<<";";
                                    cout<<endl;
                                }
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge("A","B",true,20);
                            g.addEdge("B","D",true,20);
                            g.addEdge("A","C",true,20);
                            g.addEdge("C","D",true,20);
                            g.addEdge("A","D",true,20);
                            g.print();
                            return 0;
                        }
                        */
                        break;
                    }
        case 272 :  {
                        /*
                        class Graph
                        {
                            map<int,list<int>> l;

                            public:
                            void addEdge(int x,int y)
                            {
                                l[x].push_back(y);
                                l[y].push_back(x);
                            }

                            void bfs(int src)
                            {
                                map<int, bool> visited;
                                queue<int> q;
                                q.push(src);
                                visited[src]=true;
                                while(!q.empty())
                                {
                                    int temp = q.front();
                                    q.pop();
                                    cout<<temp<<" ";
                                    for(int x : l[temp])
                                    {
                                        if(!visited[x])
                                        {
                                            q.push(x);
                                            visited[x]=true;
                                        }
                                    }
                                }
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge(0,1);
                            g.addEdge(0,3);
                            g.addEdge(1,2);
                            g.addEdge(2,3);
                            g.addEdge(3,4);
                            g.addEdge(4,5);
                            g.bfs(0);
                            return 0;
                        }
                        */
                        break;
                    }
        case 273 :  {
                        /*
                        class Graph
                        {
                            map<int,list<int>> l;

                            public:
                            void addEdge(int x,int y)
                            {
                                l[x].push_back(y);
                                l[y].push_back(x);
                            }

                            void bfs(int src)
                            {
                                map<int,int> dist;
                                queue<int> q;
                                q.push(src);
                                for(auto x:l)
                                    dist[x.first] = INT_MAX;
                                dist[src]=0;
                                while(!q.empty())
                                {
                                    int temp = q.front();
                                    q.pop();
                                    for(int x:l[temp])
                                    {
                                        if(dist[x]==INT_MAX)
                                        {
                                            q.push(x);
                                            dist[x]=dist[temp]+1;
                                        }
                                    }
                                }
                                for(auto x:dist)
                                {
                                    cout<<x.first<<" "<<x.second<<endl;
                                }
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge(0,1);
                            g.addEdge(0,3);
                            g.addEdge(1,2);
                            g.addEdge(2,3);
                            g.addEdge(3,4);
                            g.addEdge(4,5);
                            g.bfs(0);
                            return 0;
                        }
                        */
                        break;
                    }
        case 274 :  {
                        /*
                        class Graph
                        {
                            map<int,list<int>> l;
                            map<int,int> path;

                            public:
                            void addEdge(int x,int y)
                            {   //only one edge
                                l[x].push_back(y);
                            }

                            void bfs(int src, int dest)
                            {
                                map<int,int> dist;
                                queue<int> q;
                                q.push(src);
                                for(auto x:l)
                                    dist[x.first] = INT_MAX;
                                dist[src]=0;
                                while(!q.empty())
                                {
                                    int temp = q.front();
                                    q.pop();
                                    for(int x:l[temp])
                                    {
                                        if(dist[x]==INT_MAX)
                                        {
                                            q.push(x);
                                            dist[x]=dist[temp]+1;
                                            path[x] = temp;
                                        }
                                    }
                                }
                                for(auto x:dist)
                                {
                                    cout<<x.first<<" "<<x.second<<endl;
                                }
                                cout<<dist[dest];
                                int temp = dest;
                                while(temp != src)
                                {
                                    cout<<temp<<"<----";
                                    temp = path[temp];
                                }
                                cout<<src<<endl;
                            }
                        };

                        int main()
                        {
                            int board[50];
                            memset(board,0,sizeof(board));
                            board[2]=13;
                            board[5]=2;
                            board[9]=18;
                            board[18]=11;
                            board[17]=-13;
                            board[20]=-14;
                            board[24]=-8;
                            board[25]=10;
                            board[32]=-2;
                            board[34]=-22;

                            Graph g;
                            for(int i=0;i<=36;i++)
                            {
                                for(int dice=1;dice<=6;dice++)
                                {
                                    int j = i+dice;
                                    j += board[j];
                                    if(j<=36)
                                        g.addEdge(i,j);
                                }
                            }

                            g.addEdge(36,36);
                            g.bfs(0,36);
                            return 0;
                        }
                        */
                        break;
                    }
        case 275 :  {
                        /*
                        class Graph
                        {
                            map<int,list<int>> l;

                            public:
                            void addEdge(int x,int y)
                            {
                                l[x].push_back(y);
                                l[y].push_back(x);
                            }

                            void dfs_helper(int src, map<int,bool> &v)
                            {
                                cout<<src<<" ";
                                v[src]=true;
                                for(auto x:l[src])
                                {
                                    if(!v[x])
                                    {
                                        v[x] = true;
                                        dfs_helper(x,v);
                                    }
                                }
                            }

                            void dfs(int src)
                            {
                                map<int,bool> visited;
                                for(auto x:l)
                                    visited[x.first] = false;
                                dfs_helper(src,visited);
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge(0,1);
                            g.addEdge(0,3);
                            g.addEdge(1,2);
                            g.addEdge(2,3);
                            g.addEdge(3,4);
                            g.addEdge(4,5);
                            g.dfs(0);
                            return 0;
                        }
                        */
                        break;
                    }
        case 276 :  {
                        /*
                        class Graph
                        {
                            map<int,list<int>> l;

                            public:
                            void addEdge(int x,int y)
                            {
                                l[x].push_back(y);
                                l[y].push_back(x);
                            }

                            void dfs_helper(int src, map<int,bool> &v)
                            {
                                cout<<src<<" ";
                                v[src]=true;
                                for(auto x:l[src])
                                {
                                    if(!v[x])
                                    {
                                        v[x] = true;
                                        dfs_helper(x,v);
                                    }
                                }
                            }

                            void dfs()
                            {
                                map<int,bool> visited;
                                for(auto x:l)
                                    visited[x.first] = false;
                                int c=0;
                                for(auto p:l)
                                {
                                    if(!visited[p.first])
                                    {
                                        cout<<c<<"->";
                                        dfs_helper(p.first,visited);
                                        c++;
                                        cout<<endl;
                                    }
                                }
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge(0,1);
                            g.addEdge(0,3);
                            g.addEdge(1,2);
                            g.addEdge(2,3);
                            g.addEdge(3,4);
                            g.addEdge(4,5);
                            g.dfs();
                            return 0;
                        }
                        */
                        break;
                    }
        case 277 :  {
                        /*
                        class Graph
                        {
                            map<int,list<int>> l;

                            public:
                            void addEdge(int x,int y)
                            {
                                l[x].push_back(y);
                            }

                            void dfs_helper(int src, map<int,bool> &v, list<int> &ordering)
                            {
                                v[src]=true;
                                for(auto x:l[src])
                                {
                                    if(!v[x])
                                    {
                                        v[x] = true;
                                        dfs_helper(x,v,ordering);
                                    }
                                }
                                ordering.push_front(src);
                            }

                            void dfs()
                            {
                                map<int,bool> visited;
                                list<int> ordering;

                                for(auto x:l)
                                    visited[x.first] = false;

                                for(auto p:l)
                                {
                                    if(!visited[p.first])
                                        dfs_helper(p.first,visited,ordering);
                                }

                                for(auto x:ordering)
                                    cout<<x<< " ";
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge(0,1);
                            g.addEdge(0,3);
                            g.addEdge(1,2);
                            g.addEdge(2,3);
                            g.addEdge(3,4);
                            g.addEdge(4,5);
                            g.dfs();
                            return 0;
                        }
                        */
                        break;
                    }
        case 278 :  {
                        /*
                        class Graph
                        {
                            int v;
                            list<int> *l;

                            public:
                            Graph(int v)
                            {
                                this->v = v;
                                l = new list<int>[v];
                            }

                            void addEdge(int x, int y)
                            {
                                l[x].push_back(y);
                            }

                            void topologicalSort()
                            {
                                int inDegree[v];
                                memset(inDegree,0,sizeof(inDegree));
                                for(int i=0;i<v;i++)
                                {
                                    for(auto x:l[i])
                                        inDegree[x]++;
                                }
                                queue<int> q;
                                for(int i=0;i<v;i++)
                                {
                                    if(inDegree[i]==0)
                                        q.push(i);
                                }
                                while(!q.empty())
                                {
                                    int node = q.front();
                                    q.pop();
                                    cout<<node<<" ";
                                    for(auto x : l[node])
                                    {
                                        inDegree[x]--;
                                        if(inDegree[x]==0)
                                            q.push(x);
                                    }
                                }
                            }
                        };

                        int main()
                        {
                            Graph g(6);
                            g.addEdge(0,2);
                            g.addEdge(1,2);
                            g.addEdge(1,4);
                            g.addEdge(2,3);
                            g.addEdge(2,5);
                            g.addEdge(3,5);
                            g.addEdge(4,5);
                            g.topologicalSort();
                            return 0;
                        }
                        */
                        break;
                    }
        case 279 :  {
                        /*
                        class Graph
                        {
                            int v;
                            list<int> *l;

                            public:
                            Graph(int v)
                            {
                                this->v = v;
                                l = new list<int>[v];
                            }

                            void addEdge(int x, int y)
                            {
                                l[x].push_back(y);
                            }

                            bool isTree()
                            {
                                bool visited[v];
                                int parent[v];
                                memset(visited,false,sizeof(visited));
                                for(int i=0;i<v;i++)
                                {
                                    parent[i] = i;
                                }
                                int src=0;
                                queue<int> q;
                                q.push(src);
                                visited[src]=true;
                                while(!q.empty())
                                {
                                    int node = q.front();
                                    q.pop();
                                    for(int nbr : l[node])
                                    {
                                        if(visited[nbr]==true && parent[node]!=nbr)
                                            return false;
                                        else if(!visited[nbr])
                                        {
                                            visited[nbr]=true;
                                            parent[nbr]=node;
                                            q.push(nbr);
                                        }
                                    }
                                }
                                return true;
                            }
                        };

                        int main()
                        {
                            Graph g(4);
                            g.addEdge(0,1);
                            g.addEdge(3,2);
                            g.addEdge(1,2);
                            g.addEdge(0,3);
                            cout<<g.isTree();
                            return 0;
                        }
                        */
                        break;
                    }
        case 280 :  {
                        /*
                        class Graph
                        {
                            int v;
                            list<int> *l;

                            public:
                            Graph(int v)
                            {
                                this->v = v;
                                l = new list<int>[v];
                            }

                            void addEdge(int x, int y)
                            {
                                l[x].push_back(y);
                            }

                            bool cycleHelper(int node, bool visited[], bool stack[])
                            {
                                visited[node] = true;
                                stack[node] = true;
                                for(auto nbr : l[node])
                                {
                                    if(stack[node])
                                        return true;
                                    else if(visited[nbr]==false)
                                    {
                                        if(cycleHelper(nbr,visited,stack))
                                            return true;
                                    }
                                }
                                stack[node] = false;
                                return false;
                            }

                            bool containsCycle()
                            {
                                bool visited[v],stack[v];
                                memset(visited,false,sizeof(visited));
                                memset(stack,false,sizeof(stack));
                                return cycleHelper(0,visited,stack);
                            }
                        };

                        int main()
                        {
                            Graph g(7);
                            g.addEdge(0,1);
                            g.addEdge(1,2);
                            g.addEdge(2,3);
                            g.addEdge(3,4);
                            g.addEdge(4,5);
                            g.addEdge(1,5);
                            g.addEdge(5,6);
                            g.addEdge(4,2);
                            cout<<g.containsCycle();
                            return 0;
                        }
                        */
                        break;
                    }
        case 281 :  {
                        /*
                        class Graph
                        {
                            int v;
                            list<int> *l;

                            public:
                            Graph(int v)
                            {
                                this->v = v;
                                l = new list<int>[v];
                            }

                            void addEdge(int x, int y)
                            {
                                l[x].push_back(y);
                            }

                            bool cycleHelper(int node, bool visited[], int parent)
                            {
                                visited[node] = true;
                                for(auto nbr : l[node])
                                {
                                    if(!visited[nbr])
                                    {
                                        if(cycleHelper(nbr,visited,node))
                                            return true;
                                    }
                                    else if(nbr!=parent)
                                        return true;
                                }
                                return false;
                            }

                            bool containsCycle()
                            {
                                bool visited[v];
                                memset(visited,false,sizeof(visited));
                                return cycleHelper(0,visited,-1);
                            }
                        };

                        int main()
                        {
                            Graph g(4);
                            g.addEdge(0,1);
                            g.addEdge(3,2);
                            g.addEdge(1,2);
                            g.addEdge(0,3);
                            cout<<g.containsCycle();
                            return 0;
                        }
                        */
                        break;
                    }
        case 282 :  {
                        /*
                        class Graph
                        {
                            map<int,list<pair<int,int>>> m;

                            public:
                            void addEdge(int x,int y, int z)
                            {
                                m[x].push_back(make_pair(y,z));
                                m[y].push_back(make_pair(x,z));
                            }

                            void djikstra(int src)
                            {
                                map<int, int> dist;
                                for(auto x:m)
                                    dist[x.first] = INT_MAX;
                                set<pair<int,int>> s;
                                dist[src]=0;
                                s.insert(make_pair(0,src));
                                while(!s.empty())
                                {
                                    auto p = *(s.begin());
                                    int node = p.second;
                                    int distnode = p.first;
                                    s.erase(s.begin());
                                    for(auto y : m[node])
                                    {
                                        if(distnode + y.second < dist[y.first])
                                        {
                                            int dest = y.first;
                                            if(s.find(make_pair(dist[dest],dest))!=s.end())
                                                s.erase(s.find(make_pair(dist[dest],dest)));
                                            dist[dest] = distnode + y.second;
                                            s.insert(make_pair(dist[dest],dest));
                                        }
                                    }
                                }
                                for(auto x:dist)
                                    cout<<x.first<<"="<<x.second<<endl;
                            }
                        };

                        int main()
                        {
                            Graph g;
                            g.addEdge(1,2,1);
                            g.addEdge(1,3,4);
                            g.addEdge(2,3,1);
                            g.addEdge(3,4,2);
                            g.addEdge(1,4,7);
                            g.djikstra(1);
                            return 0;
                        }
                        */
                        break;
                    }
        case 283 :  {
                        int n;
                        cin >> n;
                        int a[n];
                        for(int i=0;i<n;i++){
                            cin >> a[i];
                        }
                        int k;
                        cin >> k;
                        sort(a,a+n);
                        for(int i=0;i<n-2;i++)
                        {
                            int j=i+1,l=n-1;
                            while(j<l){
                                if(a[i]+a[j]+a[l]==k){
                                    cout << a[i]<<", "<<a[j]<<" and "<<a[l]<<endl;
                                    j++;
                                    l--;
                                }
                                if(a[i]+a[j]+a[l]<k){
                                    j++;
                                }
                                if(a[i]+a[j]+a[l]>k){
                                    l--;
                                }

                            }
                        }
                        break;
                    }
        case 284 :  {
                        char c[100];
                        cin.getline(c,100);
                        removeDuplicateUnsorted(c,100);
                        break;
                    }
        case 285 :  {
                        char c[100];
                        cin.getline(c,100);
                        removeDuplicateSorted(c,100);
                        break;
                    }
        case 400 :  {
                        cout<<"Thank You!"<<endl;
                        break;
                    }
        default:    {
                        cout<<"Try Again"<<endl;
                        break;
                    }
        }
    }
    while(ch!=400);
	return 0;
}
