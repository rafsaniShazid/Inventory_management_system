#include<iostream>
using namespace std;
class Item{
    int itemID;
    string itemName;
    double price;
    int quantity;
    friend class StoreManager;
public:
    Item(): itemID(0),itemName(""),price(0.0),quantity(0){}
    Item(int id,string name,double Price,int Quantity){
        itemID=id;
        itemName=name;
        price=Price;
        quantity=Quantity;
    }
    void display(){
        cout<<"ID of the item: "<<itemID<<endl;
        cout<<"Name of the item: "<<itemName<<endl;
        cout<<"Price of the item: "<<price<<endl;
        cout<<"Quantity of items in the stock: "<<quantity<<endl;
    }
    friend istream& operator>>(istream& in,Item& i){
        in>>i.itemID>>i.itemName>>i.price>>i.quantity;
        return in;
    }
    friend ostream& operator<<(ostream& out,Item& i){
        out<<"\nID of the item: "<<i.itemID<<endl;
        out<<"Name of the item: "<<i.itemName<<endl;
        out<<"Price of the item: "<<i.price<<endl;
        out<<"Quantity of items in the stock: "<<i.quantity<<endl;
        return out;
    }
    friend Item operator++(Item i){
        i.price++;
        return i;
    }
};
class StoreManager{
public:
    static int CountLowStockItems(Item* items,int numItems,int threshold){
        int count=0;
        for(int i=0;i<numItems;i++){
            if(items[i].quantity<threshold) count++;
        }
        return count;
    }
    static void UpdatePrices(Item* items,int numItems,double percentageIncrease){
        for(int i=0;i<numItems;i++){
            items[i].price+= (items[i].price*percentageIncrease/100);
        }    
    }
};
int main(){
    Item item[4];
    for(int i=0;i<4;i++)
        cin>>item[i];
    StoreManager s;
    // cout<<s.CountLowStockItems(item,4,75);
    s.UpdatePrices(item,4,40);
    for(int i=0;i<4;i++)
        cout<<item[i];
    return 0;
}