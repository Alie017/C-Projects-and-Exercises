    #include <iostream>
    #include <queue>
    #include <bits/stdc++.h>
    #include <string>
    using namespace std;

    class Node {            //CLASS FOR QUEUE WITH LINKED LIST //
public:
queue<string> myqueue;
string mystr;
Node* link;
};
void removemyfunction(string mystr2, queue<string>& mystr){     // deleting items from the list //
queue<string>GrandQueue;
int p = mystr.size();
int cnt = 0;
        while (mystr.front() != mystr2 && !mystr.empty()) {
GrandQueue.push(mystr.front());
mystr.pop();
cnt++;}
        if (mystr.empty()) {
cout << "element not found!!" << endl;
         do {
mystr.push(GrandQueue.front());
GrandQueue.pop();
        } while (!GrandQueue.empty());
    }
            else {
mystr.pop();
            for (int j=0; !GrandQueue.empty(); j++) {
mystr.push(GrandQueue.front());
GrandQueue.pop();}
int k = p - cnt - 1;
            do {
string p = mystr.front();
mystr.pop();
mystr.push(p);}
            while (k--);}}
        void AddToTheQueue(Node** item,string mystrN,  queue<string> myqueue)  //ADDING ELEMEN TO THE QUEUE//
{
Node *nwnod, *trash;
trash = new Node;
trash->mystr= mystrN;
trash->myqueue=myqueue;
trash->link = NULL;
if (*item == NULL){
*item = trash;
}
        else do {
nwnod = *item;
nwnod = nwnod->link;
nwnod->link = trash;

}       while (nwnod->link != NULL);}
        Node inventory[112];
        void InsertIntoQueue(string mystrN , string song){
size_t szt = sizeof(inventory)/sizeof(inventory[0]);
int p=0;
size_t j = 0;
do {
        if(inventory[j].mystr==mystrN){
inventory[j].myqueue.push(song);
cout << "Your song has been added!"<<endl;
p=1;}
j++;}   while ( j < szt);
        if(p==0){
cout << "You have to enter first"<<endl;
}
}
        void showme(queue<string> queueshow)
{
queue<string> swstr = queueshow;
        while (!swstr.empty()) {
        if(swstr.front().compare("")!=0){
cout << swstr.front()<<endl;}
swstr.pop();}
}
        void BringLikedSongs(string mystrN){         //BRINGS THE LISTED SONGS //
size_t szt = sizeof(inventory)/sizeof(inventory[0]);
int p=0;
size_t j = 0;
        while ( j < szt) {
        if(inventory[j].mystr==mystrN){
cout  << mystrN << " likes the: "<<endl;
showme(inventory[j].myqueue);
p=1;}
j++;}
        if(p==0){
cout << "no record"<<""<<endl;}}
            void DeleteFromInventory(string mystrN , string song){      // DELETING THE SPECIFIC SONGS FOR ENTERED PERSON NAME //
size_t n = sizeof(inventory)/sizeof(inventory[0]);
int p=0;
size_t j = 0;
        do {if(inventory[j].mystr==mystrN)
        if(song.compare(song)==0){
removemyfunction(song, inventory[j].myqueue);
cout <<"song deleted "<<endl;
p=1;} j++;}
        while (j < n);
        if(p=0){
cout << "Register first to perform operations"<<endl;}}
        void ShowWhatsinInventory(){            // SHOWS THE ENTERED USERS TO THE PROGRAM //
cout << "People are below:"<<endl;
size_t n = sizeof(inventory)/sizeof(inventory[0]);
size_t j = 0;
        do {
            if(inventory[j].mystr.compare("")!=0){
cout << inventory[j].mystr<<endl;}
j++;}
        while (j<n);}
        void BringLikedSongs(){
cout << "All liked songs: "<<endl;
size_t n = sizeof(inventory)/sizeof(inventory[0]);
size_t j = 0;
        while ( j < n) {{
showme(inventory[j].myqueue);}j++;}}
int myint=0;
            int main()      //MAIN OF THE PROGRAM //
{
        do {
cout << "C <Name> : Creates a person with the name given in the line"<<endl;
cout << "S <Name> <song> : Sets the <Name> likes the <song>"<<endl;
cout << "E <Name> <song> : Erases the assignment (<Name> doesn't like the song anymore)."<<endl;
cout << "L <Name> : Lists the songs person <Name> likes."<< endl;
cout << "N : List the names of all of the registered people"<<endl;
cout << "M : List all the songs that are liked by anyone"<<endl;
cout<<endl;
string Mainstr;
getline(std::cin, Mainstr);
char MyChar = Mainstr.at(0);
switch (MyChar){
        case 'C':{
Node *item1 = NULL;
queue<string> firstQueue;
string NameGt= Mainstr.substr (2,Mainstr.length());
AddToTheQueue(&item1, NameGt, firstQueue);
inventory[myint]=*item1;
myint++;}
        break;
        case 'S':{
string User, Song;
istringstream iterator(Mainstr);
string Myword;
int MyTrash=0;
        while (iterator >> Myword){
        if(MyTrash==1){
User=Myword;}
        else if(MyTrash==2 || MyTrash>2){
        if(MyTrash>2){
Song+=" "+ Myword;}
        else{Song=Myword;}}
MyTrash++;}
InsertIntoQueue(User,Song);
MyTrash==0;}
        break;
        case 'E':{
string User, Song;
istringstream iterator(Mainstr);
string Myword;
int MyTrash=0;
        while (iterator >> Myword){
        if(MyTrash==1){
User=Myword;}
        if(MyTrash==2){Song=Myword;}
MyTrash++;}
DeleteFromInventory(User,Song);}
        break;
        case 'L':{
string User= Mainstr.substr (2,Mainstr.length());
BringLikedSongs(User);}
        break;
        case 'N':{
ShowWhatsinInventory();}
        break;
        case 'M':{BringLikedSongs();}
        break;
        break;}
}       while(true);}
