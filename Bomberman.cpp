#include <ncurses.h>
#include <iostream>
#include <unistd.h>
using namespace std;


int ntime=1000;
int steps=2;
const int altura=100;
const int largo=130;
//const int A[COLS][LINES];

void movek(int y,int x,int A[largo][altura]){
	if(A[x][y]==3){
		
		endwin();
	}
	mvprintw(y,x,"K");
}
void moveB(int y, int x,int A[largo][altura]){
	if(A[x][y]==3){
		
		endwin();
	}
	mvprintw(y,x,"B");
}

void verificar( int A[largo][altura] ){
	
	for(int i=0;i<altura;i++){
		for(int j=0;j<largo;j++){
			if(A[j][i]==0){
				mvprintw(i,j,"N");
			}
			else if(A[j][i]==1){
				mvprintw(i,j,"o");
			}
			else if(A[j][i]==3){
				mvprintw(i,j,"f");
			}
		}
	}
}

void kboom(int bomb[],int A[largo][altura]){

		 int y=bomb[0]%1000;
		 int x=bomb[0]/1000;
		 bomb[0]=bomb[1];
		 bomb[1]=bomb[2];
		 A[x][y]=3;
		 for(int i=0;i<altura;i++){
		 	for(int j=0;j<largo;j++){
		 		if((x==j && (i<y+5 && i>y-5)) || (y==i && (j<x+5 && j>x-5))){
		 			A[j][i]=3;
		 			mvprintw(i,j,"f");
		 		}
		 	}
		 }
}


int main(){

	initscr();








	curs_set(0);
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	printw("K-BOOM\n");
	printw("(2)start\n");
	printw("Aprete control+c para salir");
	int A[largo][altura];
	int ch;
	while(1){
		ch=getch();

		/*if(ch==(int)'1'){
				int cont=0;
				int bomb[3];
				int x=5,y=5;
				int ntime=1000;
				int steps=2;
				for(int i=0;i<altura;i++){
					for(int j=0;j<largo;j++){
						if(j==1||j==largo-1){
							A[j][i]=0;
						}
						else if(i==1||i==altura-1)
							A[j][i]=0;
						else
							A[j][i]=2;
					}
				}
				while((ch = getch()) != 'q'){
					movek(y,x,A);
				    ch=getch();
					verificar(A);
					if(A[x][y]==3){
							break;
						}
					
						if(ch==KEY_UP||ch==(int)'w'){
							for(int i=0;i<steps;i++){
								if(y==0||A[x][y]==0){
									y=y+1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);	
									break;
								}
								y--;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);
							}
						}
					
						if(ch==KEY_DOWN||ch==(int)'s'){
							for(int i=0;i<steps;i++){
								if(y==LINES||A[x][y]==0){
									y=y-1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);	
									break;
								}
								y++;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);	
							}
						}
					
						if(ch==KEY_RIGHT||ch==(int)'d'){
							for(int i=0;i<steps;i++){
								if(x==COLS||A[x][y]==0){
									x=x-1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);
									break;
								}
								x++;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);
							}
						}
					
						if(ch==KEY_LEFT||ch==(int)'a'){
							for(int i=0;i<steps;i++){
								if(x==-1||A[x][y]==0){
									x=x+1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);	
									break;
								}
								x--;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);
							}
						}
						if(ch==(int)' '){
							for(int i=0;i<altura;i++){
								for(int j=0;j<largo;j++){
									if(i==y&&j==x){
										A[j][i]=1;
										bomb[cont]=(j*1000)+i;
										if(cont==2){
											kboom(bomb,A);
										}else
											cont++;

									}
									if(A[j][i]==1){
										mvprintw(i,j,"o");	
								}								}
							}
						}

						}
						
				}		
		
	
			 endwin();*/		

			
	if(ch==(int)'2'){
		
		int x=altura-10,y=10,w=10,z=10;
		int contK=0, contB=0;
		int ntime=10000;
		int bombK[3];
		int bombB[3];
		int steps=2;
		for(int i=0;i<altura;i++){
			for(int j=0;j<largo;j++){
				if(j==1||j==largo-1){
					A[j][i]=0;
				}
				else if(i==1||i==altura-1)
					A[j][i]=0;
				else
					A[j][i]=2;
			}
		}
	while(1){
		movek(y,x,A);
		moveB(z,w,A);
		ch=getch();
		verificar(A);
		if(A[x][y]==3){
			break;
		}
		if(A[w][z]==3){
			break;
		}
		
			if(ch==KEY_UP){
				for(int i=0;i<steps;i++){
					if(y==0||A[x][y]==0){
						y=y+1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					y--;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==KEY_DOWN){
				for(int i=0;i<steps;i++){
					if(y==LINES||A[x][y]==0){
						y=y-1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);	
						break;
					}
					y++;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==KEY_RIGHT){
				for(int i=0;i<steps;i++){
					if(x==COLS||A[x][y]==0){
						x=x-1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					x++;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
		
			if(ch==KEY_LEFT){
				for(int i=0;i<steps;i++){
					if(x==-1||A[x][y]==0){
						x=x+1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					x--;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
	
			if(ch==(int)' '){
				int a,b;
				a=x;
				b=y;
				A[a][b]==2;
				for(int i=0;i<altura;i++){
					for(int j=0;j<largo;j++){
						if(i==y&&j==x){
							A[j][i]=1;
							bombK[contK]=(j*1000)+i;
							if(contK==2){
								kboom(bombK,A);
							}else
								contK++;

						}
						if(A[j][i]==1){
							mvprintw(i,j,"o");
						}
					}
				}
			}
			
			if(ch==(int)'w'){
				for(int i=0;i<steps;i++){
					if(z==0||A[w][z]==0){
						z=z+1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					z--;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==(int)'s'){
				for(int i=0;i<steps;i++){
					if(z==LINES||A[w][z]==0){
						z=z-1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);	
						break;
					}
					z++;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==(int)'d'){
				for(int i=0;i<steps;i++){
					if(w==COLS||A[w][z]==0){
						w=w-1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					w++;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
		
			if(ch==(int)'a'){
				for(int i=0;i<steps;i++){
					if(w==-1||A[w][z]==0){
						w=w+1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					w--;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
	
			if(ch==(int)'e'){
				int a,b;
				a=w;
				b=z;
				A[w][z]==2;
				for(int i=0;i<altura;i++){
					for(int j=0;j<largo;j++){
						if(i==z&&j==w){
							A[j][i]=1;
							bombB[contB]=(j*1000)+i;
							if(contB==2){
								kboom(bombB,A);
							}else
								contB++;

						}
						if(A[j][i]==1){
							mvprintw(i,j,"o");
						}
					}
				}
			}	
		}	
	
	endwin();
}}}
	
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
using namespace std;


int ntime=1000;
int steps=2;
const int altura=100;
const int largo=130;
//const int A[COLS][LINES];

void movek(int y,int x,int A[largo][altura]){
	if(A[x][y]==3){
		
		endwin();
	}
	mvprintw(y,x,"K");
}
void moveB(int y, int x,int A[largo][altura]){
	if(A[x][y]==3){
		
		endwin();
	}
	mvprintw(y,x,"B");
}

void verificar( int A[largo][altura] ){
	
	for(int i=0;i<altura;i++){
		for(int j=0;j<largo;j++){
			if(A[j][i]==0){
				mvprintw(i,j,"N");
			}
			else if(A[j][i]==1){
				mvprintw(i,j,"o");
			}
			else if(A[j][i]==3){
				mvprintw(i,j,"f");
			}
		}
	}
}

void kboom(int bomb[],int A[largo][altura]){

		 int y=bomb[0]%1000;
		 int x=bomb[0]/1000;
		 bomb[0]=bomb[1];
		 bomb[1]=bomb[2];
		 A[x][y]=3;
		 for(int i=0;i<altura;i++){
		 	for(int j=0;j<largo;j++){
		 		if((x==j && (i<y+5 && i>y-5)) || (y==i && (j<x+5 && j>x-5))){
		 			A[j][i]=3;
		 			mvprintw(i,j,"f");
		 		}
		 	}
		 }
}


int main(){

	initscr();








	curs_set(0);
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	printw("K-BOOM\n");
	printw("(2)start\n");
	printw("Aprete control+c para salir");
	int A[largo][altura];
	int ch;
	while(1){
		ch=getch();

		/*if(ch==(int)'1'){
				int cont=0;
				int bomb[3];
				int x=5,y=5;
				int ntime=1000;
				int steps=2;
				for(int i=0;i<altura;i++){
					for(int j=0;j<largo;j++){
						if(j==1||j==largo-1){
							A[j][i]=0;
						}
						else if(i==1||i==altura-1)
							A[j][i]=0;
						else
							A[j][i]=2;
					}
				}
				while((ch = getch()) != 'q'){
					movek(y,x,A);
				    ch=getch();
					verificar(A);
					if(A[x][y]==3){
							break;
						}
					
						if(ch==KEY_UP||ch==(int)'w'){
							for(int i=0;i<steps;i++){
								if(y==0||A[x][y]==0){
									y=y+1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);	
									break;
								}
								y--;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);
							}
						}
					
						if(ch==KEY_DOWN||ch==(int)'s'){
							for(int i=0;i<steps;i++){
								if(y==LINES||A[x][y]==0){
									y=y-1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);	
									break;
								}
								y++;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);	
							}
						}
					
						if(ch==KEY_RIGHT||ch==(int)'d'){
							for(int i=0;i<steps;i++){
								if(x==COLS||A[x][y]==0){
									x=x-1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);
									break;
								}
								x++;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);
							}
						}
					
						if(ch==KEY_LEFT||ch==(int)'a'){
							for(int i=0;i<steps;i++){
								if(x==-1||A[x][y]==0){
									x=x+1;
									movek(y,x,A);
									usleep(ntime);
									refresh();
									clear();
									verificar(A);	
									break;
								}
								x--;
								movek(y,x,A);
								usleep(ntime);
								refresh();
								clear();
								verificar(A);
							}
						}
						if(ch==(int)' '){
							for(int i=0;i<altura;i++){
								for(int j=0;j<largo;j++){
									if(i==y&&j==x){
										A[j][i]=1;
										bomb[cont]=(j*1000)+i;
										if(cont==2){
											kboom(bomb,A);
										}else
											cont++;

									}
									if(A[j][i]==1){
										mvprintw(i,j,"o");	
								}								}
							}
						}

						}
						
				}		
		
	
			 endwin();*/		

			
	if(ch==(int)'2'){
		
		int x=altura-10,y=10,w=10,z=10;
		int contK=0, contB=0;
		int ntime=10000;
		int bombK[3];
		int bombB[3];
		int steps=2;
		for(int i=0;i<altura;i++){
			for(int j=0;j<largo;j++){
				if(j==1||j==largo-1){
					A[j][i]=0;
				}
				else if(i==1||i==altura-1)
					A[j][i]=0;
				else
					A[j][i]=2;
			}
		}
	while(1){
		movek(y,x,A);
		moveB(z,w,A);
		ch=getch();
		verificar(A);
		if(A[x][y]==3){
			break;
		}
		if(A[w][z]==3){
			break;
		}
		
			if(ch==KEY_UP){
				for(int i=0;i<steps;i++){
					if(y==0||A[x][y]==0){
						y=y+1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					y--;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==KEY_DOWN){
				for(int i=0;i<steps;i++){
					if(y==LINES||A[x][y]==0){
						y=y-1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);	
						break;
					}
					y++;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==KEY_RIGHT){
				for(int i=0;i<steps;i++){
					if(x==COLS||A[x][y]==0){
						x=x-1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					x++;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
		
			if(ch==KEY_LEFT){
				for(int i=0;i<steps;i++){
					if(x==-1||A[x][y]==0){
						x=x+1;
						movek(y,x,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					x--;
					movek(y,x,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
	
			if(ch==(int)' '){
				int a,b;
				a=x;
				b=y;
				A[a][b]==2;
				for(int i=0;i<altura;i++){
					for(int j=0;j<largo;j++){
						if(i==y&&j==x){
							A[j][i]=1;
							bombK[contK]=(j*1000)+i;
							if(contK==2){
								kboom(bombK,A);
							}else
								contK++;

						}
						if(A[j][i]==1){
							mvprintw(i,j,"o");
						}
					}
				}
			}
			
			if(ch==(int)'w'){
				for(int i=0;i<steps;i++){
					if(z==0||A[w][z]==0){
						z=z+1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					z--;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==(int)'s'){
				for(int i=0;i<steps;i++){
					if(z==LINES||A[w][z]==0){
						z=z-1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);	
						break;
					}
					z++;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);	
				}
			}
		
			if(ch==(int)'d'){
				for(int i=0;i<steps;i++){
					if(w==COLS||A[w][z]==0){
						w=w-1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					w++;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
		
			if(ch==(int)'a'){
				for(int i=0;i<steps;i++){
					if(w==-1||A[w][z]==0){
						w=w+1;
						moveB(z,w,A);
						usleep(ntime);
						refresh();
						clear();
						verificar(A);
						break;
					}
					w--;
					moveB(z,w,A);
					usleep(ntime);
					refresh();
					clear();
					verificar(A);
				}
			}
	
			if(ch==(int)'e'){
				int a,b;
				a=w;
				b=z;
				A[w][z]==2;
				for(int i=0;i<altura;i++){
					for(int j=0;j<largo;j++){
						if(i==z&&j==w){
							A[j][i]=1;
							bombB[contB]=(j*1000)+i;
							if(contB==2){
								kboom(bombB,A);
							}else
								contB++;

						}
						if(A[j][i]==1){
							mvprintw(i,j,"o");
						}
					}
				}
			}	
		}	
	
	endwin();
}}}
	

