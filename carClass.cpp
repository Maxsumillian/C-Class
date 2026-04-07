//Mahdy Ali and Maximillian Yang

#include <iostream>
#include <algorithm>
#include <string>
//#include <cstdlib>


class Car
{
	private:
		int year;
		std::string make;
		std::string model;
		int speed;
		float gallon;
		bool isCarStarted = false;
	public:
		Car(int year, std::string make, std::string model)
		:year(year), make(make), model(model)
		{
//			this -> year = year;
//			this -> make = make;
//			this -> model = model;
			speed = 0.00;
			gallon = 10.00;
		}
		
		int getYear() 			{return year;}
		std::string getMake() 	{return make;}
		std::string getModel() 	{return model;}
		int getSpeed() 			{return speed;}
		float getGallon() 		{return gallon;}
		
		
		bool accelerate() 
		{
			
			bool canAccelerate = isCarStarted;
			
			if (isCarStarted && gallon > 0)
				{
					speed += 5; 
					gallon -= 0.5;
				}
				
			if (gallon <= 0)
				{
					gallon = 0;
					speed = 0;
					canAccelerate = false;
				}
			
			return canAccelerate;
		}
		
		void breakSpeed()
		{
			if(gallon > 0)
			{
				speed -=5;
				if(isCarStarted)
					gallon -= 0.2;
			}
				
			if (gallon <= 0)
				{
					gallon = 0;
				}
				
			if (!isCarStarted)
			{
				speed = 0;
			
			}
			
			if (speed < 0)
				speed = 0;
			
		}
		
		bool fillUp()// returns wheather it actually was able to fill up or not usefule for retunring a string based on status when not using this function to display data
		{
			bool didItFill = false;
			if (!isCarStarted && speed == 0)// if car is started we cannot fill up the gas
			{
				gallon += 5;
				didItFill = true;
			}
				
			if (gallon > 22)
				gallon = 22;
			//std::clamp(gallon, 0, 22);
			
			return didItFill;
		}
		
		void startCar()
		{
			if (gallon > 0)
				isCarStarted = true;
		}
		
		void shutOff()
		{
			isCarStarted = false;
		}
		
		bool getCarStarted(){ return isCarStarted;}
		
		std::string returnStatus()
		{
			std::string isOn;
			
			if(isCarStarted)
				isOn = "is Started";
			else
				isOn = "is off";
				
			return "\n\nCar " + isOn + " | Current Speed is : " + std::to_string(speed) + " | Current Gas is : " + std::to_string(gallon);
		}
};


void Menu(Car car){
	bool repeat = true;
	
	while (repeat)
	{
//		displayStatus(car);
//		displayMenuOption();
	}
}


void displayStatus(Car car)
{
	std::cout<<car.returnStatus();	
};

int displayMenuOption()
{
	std::cout<<"\n\nChoose a option";
	std::cout<<"\n0: to exit ";
	std::cout<<"\n1: toggle car On/Off ";
	std::cout<<"\n2: accelerate car ";
	std::cout<<"\n3: break car ";
	std::cout<<"\n4: fill up car\n";
	int input;
	
	std::cin>>input;
	
	return input;
};




int main()
{
	Car testCar(2026, "Ford", "Mustang");
	
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
//	testCar.startCar();
//	std::cout<<"\nturn on";
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
//	testCar.accelerate();
//	std::cout<<"\nAccelrate";
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
//	testCar.breakSpeed();
//	std::cout<<"\nBreak car";
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
////	testCar.shutOff();
////	std::cout<<"\nTurned Car off";
//	
//	testCar.fillUp();
//	std::cout<<"\nfillup";
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//
//	
//
//	testCar.fillUp();
//	std::cout<<"\nfillup";
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
//	
//	testCar.fillUp();
//	std::cout<<"\ntest overfill";		
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
//	
//	
//	testCar.fillUp();
//	std::cout<<"\ntest overfill";
//	std::cout<<"\n Is Car Started: "<<testCar.getCarStarted()<< "|"<<testCar.getYear()<<", "<<testCar.getMake()<<" "<<testCar.getModel()<<"| Speed : "<<testCar.getSpeed()<<"| Fuel :"<<testCar.getGallon();
//	
//	std::cout<<testCar.returnStatus();		
	
	
//	displayStatus(testCar);	
	
//	char option = displayMenuOption();

//	std::cout<<option;
	
//	char option;
	bool flip = true;
	bool repeat = true;
	while (repeat)
	{
		
		displayStatus(testCar);
		int option = displayMenuOption();
		
		std::cout<<option;
		
//		if(option == '0')
//			break;
			
		switch (option) {
			case 0:
				repeat = false;
				break;
				
			case 1:
				if (flip)
					{
						testCar.startCar();
					}
					else
					{
						testCar.shutOff();
					}
				flip = !flip;
				break;
			case 2:
				if(!testCar.accelerate())
					std::cout<<"\ncar is not started or has no gas. please try again";
				
				// add fail states that return true or false to display information to the user
				break;
			case 3:
//				std::cout << "break";
				testCar.breakSpeed();
				
				break;
			case 4:
//				std::cout << "fillUp";
				
				if(!testCar.fillUp())
					std::cout<<"\nPlease Turn off car and stop car to pump gas";
				
				break;
			default:
				std::cout<<"\nPlease enter a valid selection\n\n";
		}
//		std::system("cls");
			
	}
	

}
























