#include <iostream>
using namespace std;
#include "math.h"


class jug{
	int four;
	int seven;
	int ten;
	bool vis;//true if visited
	int ** newj=new int *[6];

public:
	jug();
	jug(int a, int b, int c, bool idf);

	int getfour(){return four;}
	int getseven(){return seven;}
	int getten(){return ten;}
	bool checkvis();
	
	void genenew();

	void newjprint();

	void gotonew(jug**** k);//recursion;




};

jug::jug(){
	four=0;
	seven=0;
	ten=0;
	vis=false;
}

jug::jug(int a, int b, int c, bool idf){
	four=a;
	seven=b;
	ten=c;
	vis=idf;
}

bool jug::checkvis(){
	return vis;
}

void jug::newjprint(){
	for(int i=0; i<6;i++){
		for(int k=0;k<3;k++){
			cout<<newj[i][k]<<" ";
		}
	}
	cout<<endl;

}

void jug::genenew(){
	for(int n=0; n<6; n++){
		newj[n]=new int [3];
		for (int k=0; k<3; k++){
			newj[n][k]=0;//initialize
		}
	}
	int sum;
	//pouring a->b
	sum=four+seven;

	newj[0][0]=sum-min(sum, 7);//four
	newj[0][1]=min(sum, 7);//seven
	newj[0][2]=ten;

	//pouring a->c
	sum=four+ten;

	newj[1][0]=sum-min(sum, 10);//four
	newj[1][1]=seven;
	newj[1][2]=min(sum, 10);

	//pouring b->a
	sum=seven+four;

	newj[2][0]=min(sum, 4);
	newj[2][1]=sum-min(sum, 4);
	newj[2][2]=ten;

	//pouring b->c
	sum=seven+ten;

	newj[3][0]=four;
	newj[3][1]=sum-min(sum,10);
	newj[3][2]=min(sum, 10);

	//pouring c->a
	sum=ten+four;

	newj[4][0]=min(sum, 4);
	newj[4][1]=seven;
	newj[4][2]=sum-min(sum, 4);

	//pouring c->b
	sum=seven+ten;

	newj[5][0]=four;
	newj[5][1]=min(sum, 7);
	newj[5][2]=sum-min(sum, 7);

	//list generated


}

bool checkexist(jug* j){
	if(j->getten()==0 && j->getseven()==0 && j->getfour()==0){
		return false;
	}
	return true;
}

bool checkjug(int a, int b, int c){
	if(a==2 || b==2 || c==2){
		return true;
	}
	else
		{return false;}
}

void jug::gotonew(jug**** k){

	for(int i=0; i<6;i++){
		cout<<i<<endl;
		cout<<"[2]"<<newj[i][2]<<" "<<"[1]"<<newj[i][1]<<" "<<"[0]"<<newj[i][0]<<endl;
		if(!checkjug(newj[i][2],newj[i][1],newj[i][0])){//the next one has no 2 in it
			cout<<"there is no 2 in this"<<endl;
			//cout<<"here2"<<endl;
			if(k[newj[i][2]][newj[i][1]][newj[i][0]]!=0){//there exist a this
				cout<<"this place exists"<<endl;

				if(!k[newj[i][2]][newj[i][1]][newj[i][0]]->checkvis()){//has not been visited
					cout<<"here4"<<endl;

					k[newj[i][2]][newj[i][1]][newj[i][0]]->genenew();//visit
					k[newj[i][2]][newj[i][1]][newj[i][0]]->gotonew(k);
				}//
				else
					cout<<"this has been visited, continue"<<endl;
					//continue;
			}
			else{//creat one if there does not exist one
				cout<<"create the next one"<<endl;
				k[newj[i][2]][newj[i][1]][newj[i][0]]=new jug(newj[i][0],newj[i][1],newj[i][2],true);
				k[newj[i][2]][newj[i][1]][newj[i][0]]->genenew();
				k[newj[i][2]][newj[i][1]][newj[i][0]]->gotonew(k);							
			}
		}
		else{//success
			cout<<"find the solution"<<newj[i][0]<<" "<<newj[i][1]<<" "<<newj[i][2]<<endl;
			exit(0);
		}
		
	}
}

int main(){

	jug**** blist=new jug*** [12];
	for(int i=0;i<12;i++){
		blist[i]=new jug**[8];
		for(int k=0; k<8;k++){
			blist[i][k]=new jug* [5];
			for (int p=0;p<5;p++){
				blist[i][k][p]=0;
			}
		}
	}//the big list generated


	blist[0][7][4]=new jug (4,7,0, true);

	blist[0][7][4]->genenew();
	//blist[0][7][4]->newjprint();
	blist[0][7][4]->gotonew(blist);



	return 0;
}