#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<fstream>
#include<algorithm>
#include<Windows.h>

using namespace std;
class node{

public:
	char arr[54];
	string action;
	int cost;
	node * parent;
	node()
	{
		cost = 0;
		parent = nullptr;
		action = "";
		for(int i = 0 ;i < 54 ;i++)
		{
			arr[i] = 0;
		}
	}


	const node & operator = (const node & secondobject)
	{
		if(this != &secondobject)
		{
			for(int i = 0 ; i<54 ; i++)
			{
				arr[i] = secondobject.arr[i];
			}
		}

		return *this;
	}


	node(const node & rightobj)
	{
		for(int i = 0 ; i<54 ; i++)
		{
			arr[i] = rightobj.arr[i];
		}
	}

};
void solution_function(node * result)
{
	//here i will do backtracking 
	stack<node *> record_of_path;
	record_of_path.push(result);
	while (result->parent !=nullptr)
	{
		node * temp = result->parent;
		record_of_path.push(temp);
		result = result->parent;
	}

	//this function prints the whole path on the screen
	while(!record_of_path.empty())
	{
		node * temp1 = record_of_path.top();
		cout<<temp1->action;
		cout<<endl;
		record_of_path.pop();
	}


}
bool goal_test(node * n,node *goal_node)
{
	bool flag;
	flag = true;
	for(int  i = 0 ;i < 54 ;i ++)
	{
		if(n->arr[i]!=goal_node->arr[i])
		{
			flag = false;
		}

	}


	return flag;
}
void move_top_clockwise(node * n)
{
	char temp1;
	char temp2;
	char temp3;

	temp1=n->arr[18];
	temp2=n->arr[19];
	temp3=n->arr[20];

	n->arr[18]=n->arr[0];
	n->arr[19]=n->arr[1];
	n->arr[20]=n->arr[2];

	n->arr[0]=n->arr[9];
	n->arr[1]=n->arr[10];
	n->arr[2]=n->arr[11];

	n->arr[9]=n->arr[45];
	n->arr[10]=n->arr[46];
	n->arr[11]=n->arr[47];

	n->arr[45]=temp1;
	n->arr[46]=temp2;
	n->arr[47]=temp3;


	char temp4;
	char temp5;
	char temp6;
	char temp7;
	char temp8;
	char temp9;
	char temp10;
	char temp11;
	char temp12;

	temp4=n->arr[27];
	temp5=n->arr[28];
	temp6=n->arr[29];
	temp7=n->arr[30];
	temp8=n->arr[31];
	temp9=n->arr[32];
	temp10=n->arr[33];
	temp11=n->arr[34];
	temp12=n->arr[35];

	n->arr[27]=temp10;
	n->arr[28]=temp7;
	n->arr[29]=temp4;
	n->arr[30]=temp11;
	n->arr[31]=temp8;
	n->arr[32]=temp5;
	n->arr[33]=temp12;
	n->arr[34]=temp9;
	n->arr[35]=temp6;

}
void move_top_anticlockwise(node * n)
{
	move_top_clockwise(n);
	move_top_clockwise(n);
	move_top_clockwise(n);

}
void move_bottom_clockwise(node * n)
{


	char temp1;
	char temp2;
	char temp3;

	temp1=n->arr[51];
	temp2=n->arr[52];
	temp3=n->arr[53];

	n->arr[51]=n->arr[15];
	n->arr[52]=n->arr[16];
	n->arr[53]=n->arr[17];

	n->arr[15]=n->arr[6];
	n->arr[16]=n->arr[7];
	n->arr[17]=n->arr[8];

	n->arr[6]=n->arr[24];
	n->arr[7]=n->arr[25];
	n->arr[8]=n->arr[26];

	n->arr[24]=temp1;
	n->arr[25]=temp2;
	n->arr[26]=temp3;


	char temp4;
	char temp5;
	char temp6;
	char temp7;
	char temp8;
	char temp9;
	char temp10;
	char temp11;
	char temp12;

	temp4=n->arr[36];
	temp5=n->arr[37];
	temp6=n->arr[38];
	temp7=n->arr[39];
	temp8=n->arr[40];
	temp9=n->arr[41];
	temp10=n->arr[42];
	temp11=n->arr[43];
	temp12=n->arr[44];

	n->arr[36]=temp10;
	n->arr[37]=temp7;
	n->arr[38]=temp4;
	n->arr[39]=temp11;
	n->arr[40]=temp8;
	n->arr[41]=temp5;
	n->arr[42]=temp12;
	n->arr[43]=temp9;
	n->arr[44]=temp6;

}
void move_bottom_anticlockwise(node * n)
{
	move_bottom_clockwise(n);
	move_bottom_clockwise(n);
	move_bottom_clockwise(n);

}
void move_left_clockwise(node * n)
{	
	char temp1;
	char temp2;
	char temp3;

	temp1=n->arr[47];
	temp2=n->arr[50];
	temp3=n->arr[53];

	n->arr[53]=n->arr[36];
	n->arr[50]=n->arr[39];
	n->arr[47]=n->arr[42];

	n->arr[36]=n->arr[0];
	n->arr[39]=n->arr[3];
	n->arr[42]=n->arr[6];

	n->arr[0]=n->arr[27];
	n->arr[3]=n->arr[30];
	n->arr[6]=n->arr[33];

	n->arr[27]=temp3;
	n->arr[30]=temp2;
	n->arr[33]=temp1;


	char temp4;
	char temp5;
	char temp6;
	char temp7;
	char temp8;
	char temp9;
	char temp10;
	char temp11;
	char temp12;

	temp4=n->arr[18];
	temp5=n->arr[19];
	temp6=n->arr[20];
	temp7=n->arr[21];
	temp8=n->arr[22];
	temp9=n->arr[23];
	temp10=n->arr[24];
	temp11=n->arr[25];
	temp12=n->arr[26];

	n->arr[18]=temp10;
	n->arr[19]=temp7;
	n->arr[20]=temp4;
	n->arr[21]=temp11;
	n->arr[22]=temp8;
	n->arr[23]=temp5;
	n->arr[24]=temp12;
	n->arr[25]=temp9;
	n->arr[26]=temp6;

}
void move_left_anticlockwise(node * n)
{

	move_left_clockwise(n);
	move_left_clockwise(n);
	move_left_clockwise(n);


}
void move_right_clockwise(node * n)
{	char temp1;
char temp2;
char temp3;

temp1=n->arr[29];
temp2=n->arr[32];
temp3=n->arr[35];

n->arr[29]=n->arr[2];
n->arr[32]=n->arr[5];
n->arr[35]=n->arr[8];

n->arr[2]=n->arr[38];
n->arr[5]=n->arr[41];
n->arr[8]=n->arr[44];

n->arr[38]=n->arr[51];
n->arr[41]=n->arr[48];
n->arr[44]=n->arr[45];

n->arr[45]=temp3;
n->arr[48]=temp2;
n->arr[51]=temp1;


char temp4;
char temp5;
char temp6;
char temp7;
char temp8;
char temp9;
char temp10;
char temp11;
char temp12;

temp4=n->arr[9];
temp5=n->arr[10];
temp6=n->arr[11];
temp7=n->arr[12];
temp8=n->arr[13];
temp9=n->arr[14];
temp10=n->arr[15];
temp11=n->arr[16];
temp12=n->arr[17];

n->arr[9]=temp10;
n->arr[10]=temp7;
n->arr[11]=temp4;
n->arr[12]=temp11;
n->arr[13]=temp8;
n->arr[14]=temp5;
n->arr[15]=temp12;
n->arr[16]=temp9;
n->arr[17]=temp6;

}
void move_right_anticlockwise(node * n)
{
	move_right_clockwise(n);
	move_right_clockwise(n);
	move_right_clockwise(n);
}
void move_front_clockwise(node * n)
{

	char temp1;
	char temp2;
	char temp3;

	temp1=n->arr[33];
	temp2=n->arr[34];
	temp3=n->arr[35];

	n->arr[33]=n->arr[26];
	n->arr[34]=n->arr[23];
	n->arr[35]=n->arr[20];

	n->arr[20]=n->arr[36];
	n->arr[23]=n->arr[37];
	n->arr[26]=n->arr[38];

	n->arr[36]=n->arr[15];
	n->arr[37]=n->arr[12];
	n->arr[38]=n->arr[9];

	n->arr[9]=temp1;
	n->arr[12]=temp2;
	n->arr[15]=temp3;


	char temp4;
	char temp5;
	char temp6;
	char temp7;
	char temp8;
	char temp9;
	char temp10;
	char temp11;
	char temp12;

	temp4=n->arr[0];
	temp5=n->arr[1];
	temp6=n->arr[2];
	temp7=n->arr[3];
	temp8=n->arr[4];
	temp9=n->arr[5];
	temp10=n->arr[6];
	temp11=n->arr[7];
	temp12=n->arr[8];

	n->arr[0]=temp10;
	n->arr[1]=temp7;
	n->arr[2]=temp4;
	n->arr[3]=temp11;
	n->arr[4]=temp8;
	n->arr[5]=temp5;
	n->arr[6]=temp12;
	n->arr[7]=temp9;
	n->arr[8]=temp6;

}
void move_front_anticlockwise(node * n)
{

	move_front_clockwise(n);
	move_front_clockwise(n);
	move_front_clockwise(n);
}
void move_back_clockwise(node * n)
{

	char temp1;
	char temp2;
	char temp3;

	temp1=n->arr[27];
	temp2=n->arr[28];
	temp3=n->arr[29];

	n->arr[27]=n->arr[11];
	n->arr[28]=n->arr[14];
	n->arr[29]=n->arr[17];

	n->arr[11]=n->arr[44];
	n->arr[14]=n->arr[43];
	n->arr[17]=n->arr[42];

	n->arr[42]=n->arr[18];
	n->arr[43]=n->arr[21];
	n->arr[44]=n->arr[24];

	n->arr[18]=temp3;
	n->arr[21]=temp2;
	n->arr[24]=temp1;



	char temp4;
	char temp5;
	char temp6;
	char temp7;
	char temp8;
	char temp9;
	char temp10;
	char temp11;
	char temp12;

	temp4=n->arr[45];
	temp5=n->arr[46];
	temp6=n->arr[47];
	temp7=n->arr[48];
	temp8=n->arr[49];
	temp9=n->arr[50];
	temp10=n->arr[51];
	temp11=n->arr[52];
	temp12=n->arr[53];

	n->arr[45]=temp10;
	n->arr[46]=temp7;
	n->arr[47]=temp4;
	n->arr[48]=temp11;
	n->arr[49]=temp8;
	n->arr[50]=temp5;
	n->arr[51]=temp12;
	n->arr[52]=temp9;
	n->arr[53]=temp6;

}
void move_back_anticlockwise(node * n)
{
	move_back_clockwise(n);
	move_back_clockwise(n);
	move_back_clockwise(n);
}
vector<node *> successor_function(node * cube)
{
	vector <node *> all_successors;
	//Move the top clockwise
	node * first_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		first_child ->arr[i] = cube ->arr[i];
	}
	first_child->parent=cube;
	first_child->cost = cube->cost + 1;
	first_child->action = "Move the top clockwise";
	move_top_clockwise(first_child);
	all_successors.push_back(first_child);



	//Move the top anticlockwise
	node * second_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		second_child ->arr[i] = cube ->arr[i];
	}
	second_child->parent=cube;
	second_child->cost = cube->cost + 1;
	second_child->action = "Move the top anticlockwise";
	move_top_anticlockwise(second_child);
	all_successors.push_back(second_child);



	//Move the bottom clockwise
	node * third_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		third_child ->arr[i] = cube ->arr[i];
	}

	third_child->parent=cube;
	third_child->cost = cube->cost + 1;
	third_child->action = "Move the bottom clockwise";
	move_bottom_clockwise(third_child);
	all_successors.push_back(third_child);



	//Move the bottom anticlockwise
	node * fourth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		fourth_child ->arr[i] = cube ->arr[i];
	}
	fourth_child->parent=cube;
	fourth_child->cost = cube->cost + 1;
	fourth_child->action = "Move the bottom anticlockwise";
	move_bottom_anticlockwise(fourth_child);
	all_successors.push_back(fourth_child);



	//Move the left clockwise
	node * fifth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		fifth_child ->arr[i] = cube ->arr[i];
	}
	fifth_child->parent=cube;
	fifth_child->cost = cube->cost + 1;
	fifth_child->action = "Move the left clockwise";
	move_left_clockwise(fifth_child);
	all_successors.push_back(fifth_child);


	//Move the left anticlockwise
	node * sixth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		sixth_child ->arr[i] = cube ->arr[i];
	}
	sixth_child->parent=cube;
	sixth_child->cost = cube->cost + 1;
	sixth_child->action = "Move the left anticlockwise";
	move_left_anticlockwise(sixth_child);
	all_successors.push_back(sixth_child);


	//Move the right clockwise
	node * seventh_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		seventh_child ->arr[i] = cube ->arr[i];
	}
	seventh_child->parent=cube;
	seventh_child->cost = cube->cost + 1;
	seventh_child->action = "Move the right clockwise";
	move_right_clockwise(seventh_child);
	all_successors.push_back(seventh_child);

	//Move the right anticlockwise
	node * eigth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		eigth_child ->arr[i] = cube ->arr[i];
	}
	eigth_child->parent=cube;
	eigth_child->cost = cube->cost + 1;
	eigth_child->action = "Move the right anticlockwise";
	move_right_anticlockwise(eigth_child);
	all_successors.push_back(eigth_child);

	//Move the front clockwise
	node * ninth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		ninth_child ->arr[i] = cube ->arr[i];
	}


	ninth_child->parent=cube;
	ninth_child->cost = cube->cost + 1;
	ninth_child->action = "Move the front clockwise";
	move_front_clockwise(ninth_child);
	all_successors.push_back(ninth_child);

	//Move the front anticlockwise
	node * tenth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		tenth_child ->arr[i] = cube ->arr[i];
	}
	tenth_child->parent=cube;
	tenth_child->cost = cube->cost + 1;
	tenth_child->action = "Move the front anticlockwise";
	move_front_anticlockwise(tenth_child);
	all_successors.push_back(tenth_child);

	//Move the back clockwise
	node * eleventh_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		eleventh_child ->arr[i] = cube ->arr[i];
	}
	eleventh_child->parent=cube;
	eleventh_child->cost = cube->cost + 1;
	eleventh_child->action = "Move the back clockwise";
	move_back_clockwise(eleventh_child);
	all_successors.push_back(eleventh_child);

	//Move the back anticlockwise
	node * twelth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		twelth_child ->arr[i] = cube ->arr[i];
	}
	twelth_child->parent=cube;
	twelth_child->cost = cube->cost +  1;
	twelth_child->action = "Move the back anticlockwise";
	move_back_anticlockwise(twelth_child);
	all_successors.push_back(twelth_child);

	return all_successors;
}
vector<node *> successor_function_for_uniform_cost_search(node * cube)
{
	vector <node *> all_successors;
	//Move the top clockwise
	node * first_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		first_child ->arr[i] = cube ->arr[i];
	}
	first_child->parent=cube;
	first_child->cost = cube->cost + (rand()%40 + 1);
	first_child->action = "Move the top clockwise";
	move_top_clockwise(first_child);
	all_successors.push_back(first_child);



	//Move the top anticlockwise
	node * second_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		second_child ->arr[i] = cube ->arr[i];
	}
	second_child->parent=cube;
	second_child->cost = cube->cost + (rand() % 40 + 1);
	second_child->action = "Move the top anticlockwise";
	move_top_anticlockwise(second_child);
	all_successors.push_back(second_child);



	//Move the bottom clockwise
	node * third_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		third_child ->arr[i] = cube ->arr[i];
	}

	third_child->parent=cube;
	third_child->cost = cube->cost + (rand()%40 + 1);
	third_child->action = "Move the bottom clockwise";
	move_bottom_clockwise(third_child);
	all_successors.push_back(third_child);



	//Move the bottom anticlockwise
	node * fourth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		fourth_child ->arr[i] = cube ->arr[i];
	}
	fourth_child->parent=cube;
	fourth_child->cost = cube->cost + (rand() % 40 + 1);
	fourth_child->action = "Move the bottom anticlockwise";
	move_bottom_anticlockwise(fourth_child);
	all_successors.push_back(fourth_child);



	//Move the left clockwise
	node * fifth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		fifth_child ->arr[i] = cube ->arr[i];
	}
	fifth_child->parent=cube;
	fifth_child->cost = cube->cost + (rand()% 40 + 1);
	fifth_child->action = "Move the left clockwise";
	move_left_clockwise(fifth_child);
	all_successors.push_back(fifth_child);


	//Move the left anticlockwise
	node * sixth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		sixth_child ->arr[i] = cube ->arr[i];
	}
	sixth_child->parent=cube;
	sixth_child->cost = cube->cost + (rand() % 40 + 1);
	sixth_child->action = "Move the left anticlockwise";
	move_left_anticlockwise(sixth_child);
	all_successors.push_back(sixth_child);


	//Move the right clockwise
	node * seventh_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		seventh_child ->arr[i] = cube ->arr[i];
	}
	seventh_child->parent=cube;
	seventh_child->cost = cube->cost + (rand()%40 + 1);
	seventh_child->action = "Move the right clockwise";
	move_right_clockwise(seventh_child);
	all_successors.push_back(seventh_child);

	//Move the right anticlockwise
	node * eigth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		eigth_child ->arr[i] = cube ->arr[i];
	}
	eigth_child->parent=cube;
	eigth_child->cost = cube->cost + (rand()%40 + 1);
	eigth_child->action = "Move the right anticlockwise";
	move_right_anticlockwise(eigth_child);
	all_successors.push_back(eigth_child);

	//Move the front clockwise
	node * ninth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		ninth_child ->arr[i] = cube ->arr[i];
	}


	ninth_child->parent=cube;
	ninth_child->cost = cube->cost + (rand() % 40 + 1);
	ninth_child->action = "Move the front clockwise";
	move_front_clockwise(ninth_child);
	all_successors.push_back(ninth_child);

	//Move the front anticlockwise
	node * tenth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		tenth_child ->arr[i] = cube ->arr[i];
	}
	tenth_child->parent=cube;
	tenth_child->cost = cube->cost + (rand()%40 + 1);
	tenth_child->action = "Move the front anticlockwise";
	move_front_anticlockwise(tenth_child);
	all_successors.push_back(tenth_child);

	//Move the back clockwise
	node * eleventh_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		eleventh_child ->arr[i] = cube ->arr[i];
	}
	eleventh_child->parent=cube;
	eleventh_child->cost = cube->cost + (rand()%40 + 1);
	eleventh_child->action = "Move the back clockwise";
	move_back_clockwise(eleventh_child);
	all_successors.push_back(eleventh_child);

	//Move the back anticlockwise
	node * twelth_child = new node(); 
	for(int  i = 0 ;i < 54 ; i ++)
	{
		twelth_child ->arr[i] = cube ->arr[i];
	}
	twelth_child->parent=cube;
	twelth_child->cost = cube->cost + (rand() % 40 + 1);
	twelth_child->action = "Move the back anticlockwise";
	move_back_anticlockwise(twelth_child);
	all_successors.push_back(twelth_child);

	return all_successors;
}

//uninformed Searches
void breadth_first_Search(node * n,node * goal_node)
{
	bool check;
	vector<node *>explored;
	if(n==NULL)
	{
		return;
	}
	deque<node*> Q;
	Q.push_back(n);



	while(!Q.empty())
	{
		node * current=Q.front();
		check = goal_test(current,goal_node);
		explored.push_back(current);
		if(check == false)
		{
			vector<node *> childs = successor_function(current);
			for(int i = 0;i<12;i++)
			{
				if(std::find(explored.begin(), explored.end(), childs[i]) == explored.end()) {
					if(std::find(Q.begin(), Q.end(), childs[i]) == Q.end())
					{
						Q.push_back(childs[i]); ///pushing all the childs into the fringe
					}


				} 
			}

		}
		else 
		{
			solution_function(current);
			break;
		}
		Q.pop_front(); //this is the loop controler
	}
}
void Depth_first_Search(node * n,node * goal_node)
{
	stack<node *> fringe;
	vector<node *>explored;
	vector<node *> childs;
	bool check;
	fringe.push(n);
	explored.push_back(n);

	while(!fringe.empty())
	{
		node * n  = fringe.top();
		check = goal_test(n,goal_node);
		fringe.pop();
		childs = successor_function(n);

		if(check == false)
		{
			for(int i = 0;i<12;i++)
			{
				if(std::find(explored.begin(), explored.end(), childs[i]) == explored.end()) {
					fringe.push(childs[i]); 
					explored.push_back(childs[i]);
				}
			} 
		}
		else 
		{
			solution_function(n);
			break;
		}

	}
}
void uniform_cost_search(node * n)
{

}

//informed Searches
void A_Star_Search(node * n){
}

int main()
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole,6);	                 

	int position = 0;


	//this is my root node
	node * initial_node = new node();
	initial_node->parent = nullptr;
	initial_node->action = "";
	initial_node->cost = 0;


	//here i am picking the nodes from the file
	ifstream fin("input.txt");
	char number;

	while(!fin.eof())
	{
		fin.get(number);
		if(number == '\n')
		{
			continue;
		}
		initial_node->arr[position] = number;
		position++;
		if(position == 54)
		{
			break;
		}

	}

	fin.close();



	//now i will prepare here a dummmy goal node 
	node * goal_node = new  node ();


	//here i am picking the nodes from the file
	ifstream fin1("goal.txt");
	char number1;
	position = 0;

	while(!fin1.eof())
	{
		fin1.get(number1);
		if(number1 == '\n')
		{
			continue;
		}
		goal_node->arr[position] = number1;
		position++;
		if(position == 54)
		{
			break;
		}

	}

	fin1.close();
	breadth_first_Search(initial_node,goal_node);
	Depth_first_Search(initial_node,goal_node);

	
	system("pause");
	return 0;
}	