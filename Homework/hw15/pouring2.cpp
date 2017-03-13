#include <iostream>
using namespace std;

class vertex{
public:
	int p, q, r;
	bool visited;
	vertex(int a, int b, int c): p(a), q(b), r(c), visited(1) {}

    vertex& operator= (const vertex v){
    	p=v.p;
    	q=v.q;
    	r=v.r;
    	visited=v.visited;
    }

    bool compare(const vertex v){
    	if ((p==v.p)||(q==v.q)||(r==v.r))
    		return 1;
    	return 0;
    }
};


class graph{
	vertex**** v;
	int p_max,q_max,r_max;

public:
	graph (int a, int b, int c) : p_max(a), q_max(b), r_max(c), step(0), res(1){
		v = new vertex***[p_max];
		for (int i=0; i<=p_max; i++){   //counter goes from 0 to p (not p-1) because quantity can be from 0 to p
			v[i]=new vertex**[q_max];
			for (int j=0; j<=q_max; j++){
				v[i][j]= new vertex*[r_max];
				for (int k=0; k<=r_max; k++)
					v[i][j][k]=NULL;
			}
		}
	}

//DFS implementation:
private:
	int step;
	bool res;


vertex interact (int m, int n, int o, int pos1, int pos2){
	int p=p_max, q=q_max, r=r_max;
	if (pos1==1 && pos2==2){
		while ((m<p)&&(n>0)){
			m++;
			n--;
		}
	}

	if (pos1==2 && pos2==1){
		while ((n<q)&&(m>0)){
			n++;
			m--;
		}
	}	

    if (pos1==2 && pos2==3){
		while ((n<q)&&(o>0)){
			n++;
			o--;
		}
	}


    if (pos1==3 && pos2==2){
			while ((o<r)&&(n>0)){
				o++;
				n--;
			}
	}	

    if (pos1==1 && pos2==3){
		while ((m<p)&&(o>0)){
			m++;
			o--;
		}
	}

    if (pos1==3 && pos2==1){
		while ((m>=0)&&(o<r)){
			o++;
			m--;
		}
	}
		return vertex(m,n,o);
}


public:
   bool DFS (int a, int b, int c, int need){
   	cout <<"m: "<<a <<" n: "<<b<<" o: "<<c<<endl;
   	//step++;
   	cout<<"step "<<step<< endl;
    if ((b==need) || (c==need)){
    	return 1;
    }

   	if (v[a][b][c] != NULL){
   		//step--;
   		return 0;
   	}

   	v[a][b][c]= new vertex(a,b,c);
    
    vertex vt1(0,0,0);
    vt1= interact(a,b,c, 1, 2);
    vertex vt2(0,0,0);
    vt2= interact(a,b,c, 2, 3);
    vertex vt3(0,0,0);
    vt3= interact(a,b,c, 1, 3);
    vertex vt4(0,0,0);
    vt4= interact(a,b,c, 2, 1);
    vertex vt5(0,0,0);
    vt5= interact(a,b,c, 3, 2);
    vertex vt6(0,0,0);
    vt6= interact(a,b,c, 3, 1);    


    res=DFS (vt1.p, vt1.q, vt1.r, need);
		if (res==1)
			return 1;
    res=DFS(vt2.p, vt2.q, vt2.r, need);
		if (res==1)
			return 1;
    res=DFS(vt3.p, vt3.q, vt3.r, need);
		if (res==1)
			return 1;
    res=DFS(vt4.p, vt4.q, vt4.r, need);
		if (res==1)
			return 1;
    res=DFS(vt5.p, vt5.q, vt5.r, need);
		if (res==1)
			return 1;
    res=DFS(vt6.p, vt6.q, vt6.r, need);
		if (res==1)
			return 1;
	}

	int disp_step(void){
		return step;
	}

};




int main(){
	graph g1(10,7,4);
	g1.DFS(0,7,4, 2);
}

