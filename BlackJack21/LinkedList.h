/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 11-01-24
    Purpose: create the LinkedList class and the Template helper class
*/

//define header
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//library inclusions 
#include <iostream>
using namespace std; 

//template to be used with TemplateHelper class
template <typename T>

/*############################################
	Class: ListNode
	Purpose: template helper class to help move through the list
############################################*/
class ListNode
{
    private: 
        //stores data of the template type
        T data;
        

    public: 
        	
			//holds two pointers to another list node
			ListNode *next; 
			ListNode *previous; 

			//constructor 
			ListNode()
			{
				//list empty
				next = NULL;
				previous = NULL;
			}
			
			//get data at this location 
        	T getData()
        	{
				return data; 
        	}

			ListNode* getNext(){
				return next;
			}

			ListNode* getPrevious(){
				return previous;
			}

        	//set data, next and previous 

            //data
            void setData(T var)
            {
				data = var; 
            }

            //next
            void setNext(ListNode* newNext)
            {
				next = newNext; 
            }

            //previous
            void setPrevious(ListNode* newPrevious)
            {
				previous = newPrevious; 
            }

			~ListNode(){
			}
}; 

template <typename T> //put this here again cause it got mad when I took it away

/*############################################
	Class: LinkedList
	Purpose: this is our linked list where we chain together our resistors
############################################*/
class LinkedList
{
    private: 

		ListNode<T> *head;		//List head pointer
		ListNode<T> *tail;	    //List tail pointer

    public: 
	
        /*############################################
			Function: constructor 
			Purpose: initialize the list
		#############################################*/ 
        LinkedList()
        {
			//creates an empty list by assigning NULL to head and tail
            head = NULL;
            tail = NULL;
        }

        /*############################################
			Function: destructor 
			Purpose: say goodbye to the resistors 
		#############################################*/
        ~LinkedList()
		{
			while(!isEmpty()){
				pop();
			}
		}


        /*############################################
			Function: isEmpty
			Purpose: check if the list is empty or not 
		############################################*/
		bool isEmpty(){
            return (head == NULL);
        }

		/*############################################
			Function: getHead
			Purpose: return head node 
		############################################*/
		ListNode<T>* getHead() const{
    		return head;
		}

		/*############################################
			Function: getLength
			Purpose: find length of list 
		############################################*/
		int getLength() const{
            int counter = 0;
			//pointer to traverse list 
	        ListNode<T> *nodePtr = this->getHead();
	
	        //list traversal
			//loop while the traversal pointer is not at the tail
	        while(nodePtr)
	        {
		        counter++;
				//update the traversal pointer to point to the next node 
		        nodePtr = nodePtr->getNext();
				/*
				//check if traversal is pointing to tail to make sure last increment happens
		        if (nodePtr == tail)
		    	    counter++;
				*/
	        }		

	        return counter;
        }

		/*############################################
			Function: appendNode
			Purpose: insert data at the end of the list 
		############################################*/
		void appendNode(T newData){
	        ListNode<T> *newNode;  // To point to a new node by declaring a newNode pointer
	        ListNode<T> *nodePtr = this->getHead();  // To move through the list //traversal popinter

	        // Allocate a new node and store num there.
	        newNode = new ListNode<T>;
            //Resistor Values setData
			newNode->setData(newData);

			//setting next and previous to NULL
			newNode->setNext(NULL);
	        newNode->setPrevious(NULL);

	        // If there are no nodes in the list make newNode the first node.
	        if (head == NULL) 
	        {
				//both head and tail
	        	head = newNode;
	        	tail = newNode;
	        }
	        else  // Otherwise, insert newNode at end.
	        {
		        //set the current last node's next pointer to the new node
	        	tail->setNext(newNode);
				newNode->setPrevious(tail);
		
	        	//now the tail is the new node
	        	tail = newNode;
	        }
        }


		/*############################################
			Function: pop
			Purpose: pop the resistor at the front of list
		#############################################*/
		void pop()
		{
			ListNode<T> *nodePtr = this->getHead();       // To traverse the list
			ListNode<T> *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
			{
				cout << "\nThe list is already empty.\n";
				return;
			}
				
			//if there is crap there then we do stuff
			head = nodePtr->getNext();
			
			if(head != NULL)
			{
				head->setPrevious(NULL);
			}

			else
			{
				tail = NULL; //if list is empty update tail to NULL
			}

			delete nodePtr;
			return;
				
		}

		/*############################################
			Function: simplifyCircuit
			Purpose: pop the resistor at the front of list
		#############################################*/
		void simplifyCircuit(){
			double totalResistance = 0;
			double minPowerRating = 100000000; //high value so that real power rating resets it
			double currentPowerRating;
			if(isEmpty()){
				cout << "The list is empty and cannot be simplified." << endl;
				return;
			}

			while(!isEmpty()){
				ListNode<T> *nodePtr = this->getHead();

				totalResistance += nodePtr->getData().getResistance(); 
        		currentPowerRating = nodePtr->getData().getPowerRating(); 
				if(currentPowerRating < minPowerRating){
					minPowerRating = currentPowerRating;
				}

				pop();
			}
			
			T newResistor;
			newResistor.setResistance(totalResistance);
			newResistor.setPowerRating(minPowerRating); //load the minimum power rating
			newResistor.setColorCode("Rainbow"); //too much work to calculate the actual power rating so why not rainbow

			appendNode(newResistor);

			cout << "Circuit simplified with a total reistance of " << totalResistance << " and a power rating of " << minPowerRating << ".\n";

		}

		/*############################################
		Function: stream operator << 
		Purpose: make outputting easier 
		#############################################*/
        friend ostream& operator << (ostream& os, const LinkedList& L)
        {
            ListNode<T> *nodePtr = L.getHead();  // To move through the list

			while(nodePtr){
				os << nodePtr->getData() << " ";
            	nodePtr = nodePtr->getNext();
			}
			return os;
        }
	
};
#endif 