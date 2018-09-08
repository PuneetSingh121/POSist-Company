#include <bits/stdc++.h>
#include <ctime>

using namespace std;


class dataClass{
public:
int ownerId;
float value;
string ownerName;
string hashValue;
};


class Node
{
    //Public data
  public:
    std::time_t time;
    dataClass data;
    int nodeNumber;
    string nodeId;
    Node *referenceNodeId;
    Node *childReferenceNodeId;
    Node *genesisReferenceNodeId;
    string Hashvalue;

};


vector<Node*> nodeAddress;


void InsertDataInANode(Node *genesis_node){
genesis_node->time = std::time(nullptr);
//    int tempData;
    float tempValue;
    dataClass* tempData = new dataClass();
    cout<<"Root node i.e Genesis Node "<<endl;
    int tempId;
    cout<<"Owner Id: ";
    cin>>tempId;
    tempData->ownerId = tempId;

    do{
    cout<<"Value: ";
    cin>>tempValue;
    if(tempValue<=3){
    tempData->value =  tempValue;
    }else{
        cout<< endl<<"Can't add more than 3 values";
        }
    }while(tempValue>3);

    string tempName;
    cout<<endl<<"Owner's Name: ";
    cin>>tempName;
    tempData->ownerName = tempName;


    genesis_node->nodeNumber = 0;
    nodeAddress.push_back(genesis_node);
    genesis_node->nodeId = '00000000000000000000000000000000';
    genesis_node->referenceNodeId = NULL;
    genesis_node->childReferenceNodeId = NULL;
    genesis_node->genesisReferenceNodeId = genesis_node;

}

int main()
{
    Node *genesis_node = new Node();
    Node *parent_node = new Node();
    string genesis_data;
    float sum_data=0;              // Keep track of when we have to move to the next layer
    float parent_siblings_sum = 0; // Keep track of parent + parent's sibling values
    float root_node_value = 0;
    char ans;

    //
    InsertDataInANode(genesis_node);
    parent_node = genesis_node;

    do{
        cout<<endl<<"Do you want to add a new node?(Y or N) ";
        cin>>ans;
        if(ans == 'Y' || ans == 'y'){

            if(sum_data == 0){
                //New Layer is being added
                int nodeFlag = 0;
                Node *tempParentNode;
                do{
                int nodeNumber;
                cout<<endl<<"Enter the node who's child you have to add: ";
                cin>>nodeNumber;

                //TODO: Add the check to not go above the last level
                if(nodeAddress[nodeNumber]){
                    tempParentNode = nodeAddress[nodeNumber];
                    nodeFlag = 1;
                }
                else{
                    cout<<endl<<"Invalid Node number";
                }
                }while(!nodeFlag != 1);

                Node *newNode = new Node();

                InsertDataInANode(newNode);

                sum_data += newNode->data.value;
                parent_siblings_sum += newNode->data.value;
                root_node_value += newNode->data.value;
            } else{
                //Sibling is being added

                if(sum_data > parent_node->data.value){
                    sum_data = 0;
                }
            }
        }
        else
            break;
    } while (ans != 'n' || ans != 'N');

    return 0;
}
