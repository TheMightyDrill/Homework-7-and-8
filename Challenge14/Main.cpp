#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CustomerListType.h"
#include "UnorderedLinkedListType.h"
#include "QueueType.h"

using namespace std;

class Video {

	string movieName;
	int movieId;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCompany;
	int numberOfCopies;

public:
	Video() {
		this->movieName = "";
		this->movieId = -1;
		this->star1 = "";
		this->star2 = "";
		this->producer = "";
		this->director = "";
		this->productionCompany = "";
		this->numberOfCopies = 0;
	}

	Video(string movieName,
		int movieId,
		string star1,
		string star2,
		string producer,
		string director,
		string productionCompany,
		int numberOfCopies) {

		this->movieName = movieName;
		this->movieId = movieId;
		this->star1 = star1;
		this->star2 = star2;
		this->producer = producer;
		this->director = director;
		this->productionCompany = productionCompany;
		this->numberOfCopies = numberOfCopies;

		

	}

	/*Functions*/

	void displayAllInformation() {
		cout << "Name: " << this->movieName << endl;
		cout << "ID: " << this->movieId << endl;
		cout << "Starring: " << this->star1 << endl;
		cout << "Starring: " << this->star2 << endl;
		cout << "Producer: " << this->producer << endl;
		cout << "Director: " << this->director << endl;
		cout << "Production Company: " << this->productionCompany << endl;
		cout << "Copes in stock: " << this->numberOfCopies << endl;
		system("Pause");
	}

	void rentVideo() {
		if (this->numberOfCopies > 0) {
			numberOfCopies--;
			cout << "Renting: " << this->movieName << endl;
		}
	}

	void checkInVideo() {
		this->numberOfCopies++;
		cout << this->movieName << " returned succesfully." << endl;
	}

	void createVideo() {
		//hehe
		string strTemp;
		int numTemp;

		cout << "--Setting new movie--\n";

		cout << "Movie Name: ";
		cin >> strTemp;
		this->movieName = strTemp;
		cin.clear();

		cout << "Movie ID: ";
		cin >> numTemp;
		this->movieId = numTemp;
		cin.clear();

		cout << "Actor 1: ";
		cin >> strTemp;
		this->star1 = strTemp;
		cin.clear();

		cout << "Actor 2: ";
		cin >> strTemp;
		this->star2 = strTemp;
		cin.clear();

		cout << "Producer: ";
		cin >> strTemp;
		this->producer = strTemp;
		cin.clear();

		cout << "Director: ";
		cin >> strTemp;
		this->director = strTemp;
		cin.clear();

		cout << "Production Company: ";
		cin >> strTemp;
		this->productionCompany = strTemp;
		cin.clear();

		cout << "Number of copies in stock: ";
		cin >> numTemp;
		this->numberOfCopies = numTemp;
		cin.clear();
		cout << "Movie data set." << endl;
		system("pause");
	}

	/*GET*/
	string getName() {
		return this->movieName;
	}
	int getId() {
		return this->movieId;
	}
	string getStar1() {
		return this->star1;
	}
	string getStar2() {
		return this->star2;
	}
	string getProducer() {
		return this->producer;
	}
	string getDirector() {
		return this->director;
	}
	string getProductionCompany() {
		return this->productionCompany;
	}
	int getNumOfCopies() {
		return this->numberOfCopies;
	}


	/*SET*/

	void setName(string name) {
		this->movieName = name;
	}
	void setId(int id) {
		this->movieId = id;
	}
	void setStar1(string star) {
		this->star1 = star;
	}
	void setStar2(string star) {
		this->star2 = star;
	}
	void setProducer(string prod) {
		this->producer = prod;
	}
	void setDirector(string direct) {
		this->director = direct;
	}
	void setProductionCompany(string comp) {
		this->productionCompany = comp;
	}
	void setNumOfCopies(int cop) {
		this->numberOfCopies = cop;
	}
};

class videoStore {
	int numberOfVideos;
	int numberOfCustomers;
	Video video; //temp video
	Customer customer; //temp customer

	//containers
	vector<Video> videolist;
	vector<Customer> customerList;

	//parallel containers (waiting list)
	QueueType<int> customerWaitingList; //holds id
	vector<int> movieWaitingList; //holds movie id's that are out of stock

	vector<string> rentedVideos; //push video name of rented videos
public:


	/*FUNCTIONS*/

	void rentVideo() {

		int mId;
		int cId;

		cout << "Rent a movie" << endl;
		for (int i = 0; i < videolist.size(); i++) {
			cout << "Name: " << videolist[i].getName() << " Id: " << videolist[i].getId() << " Stock:" << videolist[i].getNumOfCopies() << endl;
		}
		
		cout << "Movie Id: ";
		cin >> mId;
		cout << "Customer Id: ";
		cin >> cId;

		//If movie is out of stock customer is pushed onto the queue waiting list
		if (videolist[mId].getNumOfCopies() <= 0) {
			cout << "Movie is out of stock..." << endl;
			movieWaitingList.push_back(mId);
			cout << "Id: " << customerList[cId].getId() << " - You'll be put on a waiting list." << endl;
			customerWaitingList.add(customerList[cId].getId());
			system("pause");
		}
		else {
			videolist[mId].rentVideo(); //updates stock
			rentedVideos.push_back(videolist[mId].getName()); //updates rented list
			cout << customerList[cId].getName() << " - Renting: " << videolist[mId].getName() << endl;
			system("Pause");
		}

	}

	void returnVideo() {
		int mId;
		cout << "Returning Video" << endl;
		cout << "Movie Id:";
		cin >> mId;

		videolist[mId].checkInVideo();

		//checks waiting list...
		for (int i = 0; i < movieWaitingList.size(); i++) {
			if (movieWaitingList.at(i) == mId) {

				cout << videolist[mId].getName() << " is now in stock..." << endl;
				break;

			}
		}

		//updates rented videolist

		for (int i = 0; i < rentedVideos.size(); i++) {
			if (videolist[mId].getName() == rentedVideos[i]) {
				rentedVideos[i].erase();
			}
		}

		system("pause");
	}

	void displayAllRentedVideos() {
		system("CLS");
		cout << "All rented videos" << endl;

		for (int i = 0; i < rentedVideos.size(); i++) {

			cout << "[" << i << "]: " << rentedVideos[i] << endl;

		}
		cout << "~end of list~" << endl;
		system("pause");
	}

	void addVideo() {
		video.createVideo();
		videolist.push_back(video);
	}

	void showVideoDetails() {

		system("CLS");

		int videoId;

		for (int i = 0; i < videolist.size(); i++) {
			cout << "~~ Videos ~~" << endl;
			cout <<"Video [" << i << "]: " << videolist[i].getName() << endl;
		}
		cout << "End of list" << endl;
		cout << endl;
		cout << "Show video: ";
		cin >> videoId;
		system("CLS");

		videolist[videoId].displayAllInformation();

		cin.clear();
	}

	void showCustomerDetails() {

		system("CLS");

		int customerId;

		for (int i = 0; i < customerList.size(); i++) {
			cout << "~~ Customers ~~" << endl;
			cout << "Customer [" << i << "]: " << customerList[i].getName() << endl;
		}
		cout << "End of list" << endl;
		cout << endl;
		cout << "Show customer: ";
		cin >> customerId;
		system("CLS");

		customerList[customerId].displayAllInformation();

		cin.clear();
	}

	void createNewCustomer() {
		customer.newCustomer();
		customerList.push_back(customer);
	}
	
	videoStore() {
		numberOfVideos = 0;
		numberOfCustomers = 0;
	}
};

int main() {

	videoStore store;


	//rent a video (check out the video)
	//return or check in a video
	//create a list of videos owned by store
	//show the details of particular video
	//print a list of all videos                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         .n                                                                         
	//check whether a particular vieo is in the store
	//maintain a customre edatabase
	//print a list of all the videos rented by each customer

	//if a number of video is 0, waitlist que [cust id]
	//if customer checks in video stock updated notify customer, available for renting
	//prompt video name & stock, if 0 list all ID's of customers in waiting que
	//prompt for a cust id and list of videos rented


	bool inUse = true;
	int userInp;

	while (inUse) {

		system("CLS");

		cout << "--Welcome--\n";
		cout << "[0]Rent a video\n";//rents video for a customer
		cout << "[1]Add video\n";//adds to video database
		cout << "[2]Show video detail\n";//show detail, check in stock
		cout << "[3]Return video\n";
		cout << "[5]Display videos being rented\n";
		cout << "[6]Create new customer\n";
		cout << "[7]Show customer details\n";
		cout << endl;
		cout << "[-1 to exit]: ";

		cin >> userInp;
		cin.clear();
		switch (userInp) {
		case 0:
			store.rentVideo();
			break;
		case 1:
			store.addVideo();
			break;
		case 2:
			store.showVideoDetails();
			break;
		case 3:
			store.returnVideo();
			break;
		case 5:
			store.displayAllRentedVideos();
			break;
		case 6:
			store.createNewCustomer();
			break;
		case 7:
			store.showCustomerDetails();
			break;
		case -1:
			inUse = false;
			break;
		default:
			cout << "Error... exiting progrom" << endl;
			inUse = false;
			break;
		}

	}


	system("Pause");
	return 0;
}
