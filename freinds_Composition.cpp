

#include <iostream>

// called a forward decloration
class Sale;// basically prototype for my class used to make calsses belowe it see it exist


class Date
{
	private:
		int month;
		int day;
		int year;
		
	public:
		//older method
//		Date(int month, int day, int year)
//		{
//			this->month = month;
//			this->day = day;
//			this->year = year;
//		}
		
		//faster non default
//		Date(int month, int day, int year):month(month), day(day), year(year){}
		
		//DEAFULT WIHT NO ARGUMENT
//		Date():month(1), day(1), year(1970){}

		// does it all
		Date(int month = 1, int day = 1, int year = 1970):month(month), day(day), year(year){}

		
		
		void displayDate()
		{
			std::cout<<month<<"/"<<day<<"/"<<year;		}
			
			
};



class SalesPerson{
	
	//makes the private data here acsessable to the display funcion
	friend void display(Sale aSale, SalesPerson aSeller);
	
	//but now sales person doesn't knwo what sale is so we need to decalre it above it
	
	private:
		int idNum;
		std::string name;
	public:
		SalesPerson(int idNum, std::string name):idNum(idNum), name(name){}
		
		
		
};


class Sale
{
	//exposese the display so its accsessable
	friend void display(Sale aSale, SalesPerson aSeller); // makes the private data here acsessable to the display funcion
	// made non meber functions freinds so they can accsess private data
	
	
	private:
		Date salesDate;// composition composed of other objects
		double amount;
		int idNum;
		int transactionalNumber;
		static int nextTransaction;
	
	public:
		Sale(int month, int day, int year, double amt, int id)
			:salesDate(month, day, year),//how to make the object wiht the parameters ///==========Initialization List
			amount(amt), idNum(id)
			
		{
			transactionalNumber = nextTransaction;
			nextTransaction++;
			
			
		}
		
		Sale(double amt, int id): amount(amt), idNum(id), salesDate(1,1,1970){}
		
		
		static int getNextTransaction(){ return nextTransaction;}
		
};

int Sale::nextTransaction = 100;// :: is a scope resolution operatior


int main()
{
		//Date();
		
		std::cout<<"\n Next Transaction: "<<Sale::getNextTransaction();// if i make it statiac then i dont need the object call
		
		Sale aSale(45.67,8910);	
		std::cout<<"\n Next Transaction: "<<aSale.getNextTransaction();// if i make it statiac then i dont need the object call
		
		Sale anotherSale(2,3,2020,12.34,5678);
		std::cout<<"\n Next Transaction: "<<anotherSale.getNextTransaction();// if i make it statiac then i dont need the object call
		
		SalesPerson seller(12345, "Sara");
		
		display(aSale, seller);	
		
			
};



void display(Sale aSale, SalesPerson aSeller)
{
	std::cout<<"\nTransaction on ";
	
	aSale.salesDate.displayDate();// checks aSale then into salesDate then calls displayDate within salesdate
	//is a private variable but by being a freind it has accsess to it
	
	std::cout<<"\nSold by: "<<aSeller.idNum<< " - "<<aSeller.name;
	
	std::cout<<"\nAmount $ "<<aSale.amount;
	
	
	
}






















