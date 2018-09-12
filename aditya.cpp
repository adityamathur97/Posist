#include<bits/stdc++.h>
using namespace std;
struct Time_Stamp
{ 	int dd;
	int mm;
	int yy;
};

struct Data
{
	string own_id;
	float value;
	string own_name;
	string hashset;
};

struct Node
{
	struct Time_Stamp timestamp;
	struct Data data;	
	int node_number;
	string node_id;
       	struct Node *ref_node_id;
	vector<struct Node*>child_ref_id;
	string hashvalue; 
};

string encrypt(string input)
{	
	reverse(input.begin(),input.end());
		
	return(input);
}
string decrypt(string input)
{
	
	reverse(input.begin(),input.end());
	return(input);
}
float encryptv(float inp)
{ 
	return(inp+100);
}
float decryptv(float inp)
{
	return(inp-100);
}
bool check(int node_number,struct Node *ref_node_id)
{
	int parent_node_num=ref_node_id->node_number;
	int total_sum_of_childnn=0;
	int i;
	while(i<ref_node_id->child_ref_id.size())
	{
		total_sum_of_childnn=ref_node_id->child_ref_id[i]->node_number+total_sum_of_childnn;
	}
	
	if((parent_node_num-total_sum_of_childnn)<node_number)
	{
		return(false);

	}
	else
	{
		return(true);	
	}
	
}
 

struct Node *createNewNode(int node_number,struct Node *ref_node_id,int dd,int mm,int yy,string ownerid,float value,string ownername)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	bool flag;
	flag=check(node_number,ref_node_id);
	
	if(flag==false)
	{
		cout<<"Please provide correct Node number it is not possible to create a new node with given Node Number"<<endl;
		return(temp);
	}
	else
	{
		temp->node_number=node_number;
		temp->ref_node_id=ref_node_id;
		temp->timestamp.dd=dd;
		temp->timestamp.mm=mm;
		temp->timestamp.yy=yy;
		temp->data.own_id=encrypt(ownerid);	
		temp->data.value=encryptv(value);
		temp->data.own_name=encrypt(ownername);
		ref_node_id->child_ref_id.push_back(temp);
		
		return(temp);
	}
	
}


int main()
{
	struct Node *Genesis=(struct Node*)malloc(sizeof(struct Node));
	Genesis->ref_node_id=NULL;
	Genesis->node_number=100;
	
	createNewNode(40,Genesis,5,4,2018,"A",4000,"ujjwal");
	createNewNode(10,Genesis,16,9,2018,"A",1000,"ujjwal");
	
	int i=0;
	cout<<"printing the genesis value"<<endl;
	cout<<Genesis->node_number<<endl;
	cout<<"printing value of child Node"<<endl;
	cout<<"printing data without decryption"<<endl;
	while(i<Genesis->child_ref_id.size())
	{
		cout<<Genesis->child_ref_id[i]->node_number<<" "<<Genesis->child_ref_id[i]->timestamp.dd<<"/"<<Genesis->child_ref_id[i]->timestamp.mm<<"/"<<Genesis->child_ref_id[i]->timestamp.yy<<" "<<Genesis->child_ref_id[i]->data.own_id<<" "<<(Genesis->child_ref_id[i]->data.value)<<" "<<Genesis->child_ref_id[i]->data.own_name<<endl;
		
		i=i+1;
	}
	i=0;
	cout<<"Data after Decryption"<<endl;
	while(i<Genesis->child_ref_id.size())
	{
		cout<<Genesis->child_ref_id[i]->node_number<<" "<<Genesis->child_ref_id[i]->timestamp.dd<<"/"<<Genesis->child_ref_id[i]->timestamp.mm<<"/"<<Genesis->child_ref_id[i]->timestamp.yy<<" "<<decrypt(Genesis->child_ref_id[i]->data.own_id)<<" "<<decryptv(Genesis->child_ref_id[i]->data.value)<<" "<<decrypt(Genesis->child_ref_id[i]->data.own_name)<<endl;
		
		i=i+1;
	}

	return(0);
}