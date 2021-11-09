#include <cstdlib>
#include <iostream>
#include <queue>
#include <array>
#include <vector>

using namespace std;

class Node{
    public:
        array<int,9> game_state;//The game state of the current node
        int hn;//Heuristic for approximating the distance to the goal state
        int gn;//The depth of the current node
        int fn;//Total cost function or hn + gn
        
        //Constructor adding just the state
        Node(array<int,9> state){
            this->game_state = state;
        }

        //Copy constructor
        Node(const Node &temp){
            this->game_state = temp.game_state;
            this->hn = temp.hn;
            this->gn = temp.gn;
            this->fn = temp.fn;
        }
        
        //Constructor completing the whole node
        Node(array<int,9> state, int heuristic, int depth, int function){
            this->game_state = state;
            this->hn = heuristic;
            this->gn = depth;
            this->fn = function;
        }
        
        void setArray(array<int,9> state){
            this->game_state = state;
        }
        
        array<int,9> getArray(){
            return this->game_state;
        }
        
        void setHn(int heuristic){
            this->hn = heuristic;
        }
        
        int getHn(){
            return this->hn;
        }
        
        void setGn(int depth){
            this->gn = depth;
        }
        
        int getGn(){
            return this->gn;
        }
        
        void setFn(int function){
            this->fn = function;
        }
        
        int getFn(){
            return this->fn;
        }
};

class Problem{
    public:
        array<int,9> state;//Game state
        array<int,9> goal_state;//Goal state, will be defined in constructor.
        vector<Node> problem_check;//Vector for holding unique states
        int node_num;
        
        //Constructor
        Problem(array<int,9> initial_state){
            this->state = initial_state;
            this->goal_state = {1,2,3,4,5,6,7,8,0};
            this->node_num = 0;
            
            //Pushing back the vector of nodes with the initial puzzle
            this->problem_check.push_back(Node(initial_state, 0, 0, 0));
            
        }
        
        Node initial_test(){
            if(state == goal_state){
                Node initial = Node(state,0,0,0);
            }
        }
        
        //Swap function for changing the problem space
        array<int,9> swapIndex(array<int,9> input, int blank, int swapIndex){
            int temp = input[blank];
            input[blank] = input[swapIndex];
            input[swapIndex] = temp;
            
            return input;
        }
        
        //Checking to see if the current problem is equal to the goal state
        bool goalCheck(Node node){
            if(node.game_state == this->goal_state){
                return true;
            }
            return false;
        }
        
        //Finding the index of the empty node
        int findEmpty(Node node){ 
            for(int i = 0; i < 9; i++){
                if(node.game_state[i] == 0){
                    return i;
                } 
            }
        }
        
        bool checkNode(Node node){
            for(int i = 0; i < this->problem_check.size(); i++){
                if(node.game_state == this->problem_check[i].game_state){
                    return true;//If this returns true we have a repeated game state
                }
            }
            return false;//If we make it outside the for loop that means we have a unique game state
        }
        
        //Defining the operators for the problem (move up, down, left, right)
        //I am using a 2D representation of the puzzle to visualize how to
        //implement the puzzle in code. Picture of my work will be in the report
        
        priority_queue<Node> operators(Node node){
            this->node_num++;//Incrementing the new node being added
            priority_queue<Node> new_nodes;//New nodes being added after operations
            int blankIndex = findEmpty(node);//Finding the blank index
            
            //Move Up Operations
            //We start by checking if the move is possible depending on where
            //the blank space is at. From there we swap the tile using the
            //current state and create a new node at a lower depth using the
            //new swapped game state. We then check to see if this game state
            //already exists in the vector of game states we are accumulating.
            //If it does not exist, we add it to the vector. 
            if(blankIndex==4){
                Node up = Node(swapIndex(this->state,4,1));
                up.setGn(node.getGn()+1);
                if(!checkNode(up)){
                    new_nodes.push(up);
                    this->node_num++;
                }
            }
            if(blankIndex==5){
                Node up = Node(swapIndex(this->state,5,2));
                up.setGn(node.getGn()+1);
                if(!checkNode(up)){
                    new_nodes.push(up);
                    this->node_num++;
                }
            }
            if(blankIndex==6){
                Node up = Node(swapIndex(this->state,6,3));
                up.setGn(node.getGn()+1);
                if(!checkNode(up)){
                    new_nodes.push(up);
                    this->node_num++;
                }
            }
            if(blankIndex==7){
                Node up = Node(swapIndex(this->state,7,4));
                up.setGn(node.getGn()+1);
                if(!checkNode(up)){
                    new_nodes.push(up);
                    this->node_num++;
                }
            }
            if(blankIndex==8){
                Node up = Node(swapIndex(this->state,8,5));
                up.setGn(node.getGn()+1);
                if(!checkNode(up)){
                    new_nodes.push(up);
                    this->node_num++;
                }
            }
            if(blankIndex==9){
                Node up = Node(swapIndex(this->state,9,6));
                up.setGn(node.getGn()+1);
                if(!checkNode(up)){
                    new_nodes.push(up);
                    this->node_num++;
                }
            }
            
            //Move Down
            if(blankIndex==1){
                Node down = Node(swapIndex(this->state,1,4));
                down.setGn(node.getGn()+1);
                if(!checkNode(down)){
                    new_nodes.push(down);
                    this->node_num++;
                }
            }
            if(blankIndex==2){
                Node down = Node(swapIndex(this->state,2,5));
                down.setGn(node.getGn()+1);
                if(!checkNode(down)){
                    new_nodes.push(down);
                    this->node_num++;
                }
            }
            if(blankIndex==3){
                Node down = Node(swapIndex(this->state,3,6));
                down.setGn(node.getGn()+1);
                if(!checkNode(down)){
                    new_nodes.push(down);
                    this->node_num++;
                }
            }
            if(blankIndex==4){
                Node down = Node(swapIndex(this->state,4,7));
                down.setGn(node.getGn()+1);
                if(!checkNode(down)){
                    new_nodes.push(down);
                    this->node_num++;
                }
            }
            if(blankIndex==5){
                Node down = Node(swapIndex(this->state,5,8));
                down.setGn(node.getGn()+1);
                if(!checkNode(down)){
                    new_nodes.push(down);
                    this->node_num++;
                }
            }
            if(blankIndex==6){
                Node down = Node(swapIndex(this->state,6,9));
                down.setGn(node.getGn()+1);
                if(!checkNode(down)){
                    new_nodes.push(down);
                    this->node_num++;
                }
            }

            //Move Left
            if(blankIndex==2){
                Node left = Node(swapIndex(this->state,2,1));
                left.setGn(node.getGn()+1);
                if(!checkNode(left)){
                    new_nodes.push(left);
                    this->node_num++;
                }
            }
            if(blankIndex==3){
                Node left = Node(swapIndex(this->state,4,3));
                left.setGn(node.getGn()+1);
                if(!checkNode(left)){
                    new_nodes.push(left);
                    this->node_num++;
                }
            }
            if(blankIndex==5){
                Node left = Node(swapIndex(this->state,5,4));
                left.setGn(node.getGn()+1);
                if(!checkNode(left)){
                    new_nodes.push(left);
                    this->node_num++;
                }
            }
            if(blankIndex==6){
                Node left = Node(swapIndex(this->state,6,5));
                left.setGn(node.getGn()+1);
                if(!checkNode(left)){
                    new_nodes.push(left);
                    this->node_num++;
                }
            }
            if(blankIndex==8){
                Node left = Node(swapIndex(this->state,8,7));
                left.setGn(node.getGn()+1);
                if(!checkNode(left)){
                    new_nodes.push(left);
                    this->node_num++;
                }
            }
            if(blankIndex==9){
                Node left = Node(swapIndex(this->state,9,8));
                left.setGn(node.getGn()+1);
                if(!checkNode(left)){
                    new_nodes.push(left);
                    this->node_num++;
                }
            }

            //Move Right
            if(blankIndex==1){
                Node right = Node(swapIndex(this->state,1,2));
                right.setGn(node.getGn()+1);
                if(!checkNode(right)){
                    new_nodes.push(right);
                    this->node_num++;
                }
            }
            if(blankIndex==2){
                Node right = Node(swapIndex(this->state,2,3));
                right.setGn(node.getGn()+1);
                if(!checkNode(right)){
                    new_nodes.push(right);
                    this->node_num++;
                }
            }
            if(blankIndex==4){
                Node right = Node(swapIndex(this->state,4,5));
                right.setGn(node.getGn()+1);
                if(!checkNode(right)){
                    new_nodes.push(right);
                    this->node_num++;
                }
            }
            if(blankIndex==5){
                Node right = Node(swapIndex(this->state,5,6));
                right.setGn(node.getGn()+1);
                if(!checkNode(right)){
                    new_nodes.push(right);
                    this->node_num++;
                }
            }
            if(blankIndex==7){
                Node right = Node(swapIndex(this->state,7,8));
                right.setGn(node.getGn()+1);
                if(!checkNode(right)){
                    new_nodes.push(right);
                    this->node_num++;
                }
            }
            if(blankIndex==8){
                Node right = Node(swapIndex(this->state,8,9));
                right.setGn(node.getGn()+1);
                if(!checkNode(right)){
                    new_nodes.push(right);
                    this->node_num++;
                }
            }

            return new_nodes;

        }            
};

priority_queue<Node> uniform_cost_search(priority_queue<Node> curr_nodes, priority_queue<Node> new_nodes){
    priority_queue<Node> newQ = curr_nodes;
    while(!new_nodes.empty()){
        Node new_node = Node(new_nodes.top());
        new_node.setHn(0);
        new_node.setFn(new_node.getGn() + new_node.getHn());
        newQ.push(new_node);
        new_nodes.pop();
    }
    return newQ;
}

int misplaced_counter(array<int,9> input){
    array<int,9> goal_state = {1,2,3,4,5,6,7,8,0};
    int misplaced = 0;

    for(int i = 0; i < 9; i++){
        if(input[i] != goal_state[i]){
            misplaced++;
        }
    }

    return misplaced;
}

priority_queue<Node> misplaced_tile(priority_queue<Node> curr_nodes, priority_queue<Node> new_nodes){
    priority_queue<Node> newQ = curr_nodes;
    while(!new_nodes.empty()){
        Node new_node = Node(new_nodes.top());
        new_node.setHn(misplaced_counter(new_node.game_state));
        new_node.setFn(new_node.getGn() + new_node.getHn());
        newQ.push(new_node);
        new_nodes.pop();
    }
    return newQ;
}

priority_queue<Node> manhattan_dist(priority_queue<Node> curr_nodes, priority_queue<Node> new_nodes){

}

void general_search(Problem problem, int queue_function){
    Node initial_node = Node(problem.state,0,0,0);//Initializing the problem
    bool goal_achieved = false;//Keep looping until goal state is found.
    int max_size;//Max size number of nodes expanded.
    priority_queue<Node> nodes;//Initializing the priority queue of nodes.
    nodes.push(initial_node);//Pushing the initial problem onto the queue
    int tempQSize;

    max_size = nodes.size();//Getting the max size of the queue at one time

    switch(queue_function){
        //Case 1 is the Uniform Cost Search
        case 1:
            while(!goal_achieved){
                if(nodes.empty()){
                    cout<<"Nodes empty."<<endl;
                    exit(0);
                }
                
                //Copying a node into the copy constructor
                Node node = nodes.top();
                
                //Checking to see if the current node is the goal state
                if(problem.goalCheck(node)){
                    cout<<"Goal state found."<<endl;
                    cout<<"Total nodes expanded : "<<problem.node_num<<endl;
                    cout<<"Max queue size : "<<max_size<<endl;
                    cout<<"Depth of goal state : "<<node.getGn()<<endl;
                }

                nodes = uniform_cost_search(nodes, problem.operators(node));

                //Checking for the max queue size
                tempQSize = nodes.size();

                if(tempQSize > max_size){
                    max_size = tempQSize;
                }
            }

        //Case 2 is the Misplaced Tile Heuristic
        case 2:
            while(!goal_achieved){
                if(nodes.empty()){
                    cout<<"Nodes empty."<<endl;
                    exit(0);
                }
                
                //Copying a node into the copy constructor
                Node node = nodes.top();
                
                //Checking to see if the current node is the goal state
                if(problem.goalCheck(node)){
                    cout<<"Goal state found."<<endl;
                    cout<<"Total nodes expanded : "<<problem.node_num<<endl;
                    cout<<"Max queue size : "<<max_size<<endl;
                    cout<<"Depth of goal state : "<<node.getGn()<<endl;
                }

                nodes = misplaced_tile(nodes, problem.operators(node)); 
            }

        case 3:
            exit(0);//Manhattan Incomplete.
    }
    
    while(!goal_achieved){
        if(nodes.empty()){
            cout<<"Nodes empty."<<endl;
            exit(0);
        }
        //if()
    }
    
    
    
}

int main(int argc, char** argv) {
    int default_puzzle[9] = {1,2,3,4,5,6,7,8,0};//Puzzle of depth 0 for testing.
    int arbitrary[9];//Arbitrary puzzle to be input by user.
    int count = 0;//For keeping track of the rows when iterating below.
    int choice;//Integer for selecting the search algorithm to use.
    int index;//To keep track of the index at which the empty tile is at.
    
    //Prompting the user for the contents of the puzzle.
    cout<<"Welcome to Juan Castellon's 8-Puzzle Solver"<<endl;
    cout<<"Please indicate the empty space with a 0"<<endl;
    
    //User input for the puzzle
    cout<<"Input the number for row 1 column 1 : ";
    cin >> arbitrary[0];
    cout<<"Input the number for row 1 column 2 : ";
    cin >> arbitrary[1];
    cout<<"Input the number for row 1 column 3 : ";
    cin >> arbitrary[2];
    cout<<"Input the number for row 2 column 1 : ";
    cin >> arbitrary[3];
    cout<<"Input the number for row 2 column 2 : ";
    cin >> arbitrary[4];
    cout<<"Input the number for row 2 column 3 : ";
    cin >> arbitrary[5];
    cout<<"Input the number for row 3 column 1 : ";
    cin >> arbitrary[6];
    cout<<"Input the number for row 3 column 2 : ";
    cin >> arbitrary[7];
    cout<<"Input the number for row 3 column 3 : ";
    cin >> arbitrary[8];
    
    cout<<endl;
    
    cout<<"Puzzle Input:"<<endl;
    
    //
    for(int i = 0; i < 9; i++){
        if(arbitrary[i] == 0){
            index = i;
        }
        if(count < 3){
            count++;
            cout<<arbitrary[i];
        }
        else{
            count = 0;
            count++;
            cout<<endl;
            cout<<arbitrary[i];
        }
    }
    
    cout<<endl;
    
    //Prompting the user which search algorithm to use.
    cout<<endl;
    cout<<"Choose which search algorithm to use:"<<endl;
    cout<<"1 : Uniform Cost Search"<<endl;
    cout<<"2 : A* with Misplaced Tile Heuristic"<<endl;
    cout<<"3 : A* with Manhattan Heuristic"<<endl;
    cin >> choice;

    array<int,9> temp;

    for(int i = 0; i < 9; i++){
        temp[i] = arbitrary[i];
    }

    Problem problem = Problem(temp);

    general_search(problem, choice);
    
    return 0;
}
