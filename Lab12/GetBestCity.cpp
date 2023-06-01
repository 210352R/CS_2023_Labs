#include <iostream>
#include <vector>
using namespace std;
// Function to calculate the average time from the data array
float calculateAvgTime(vector<int> &data,int src);

// Function to calculate the average time from the data array
void printOutput(vector<int> &data,int src);

// Function to get the vertex with the minimum 
int getMinimum(vector<int> &data, vector<bool> &isVisit){
    int mins = INT_MAX;  // Assign values to integer maximum
    int minIndex = 0;
    for(int i=0;i<data.size();i++){
        if(isVisit[i] == false && data[i]<=mins){
            mins = data[i];
            minIndex = i;
        }
    }
    return minIndex;
}


// Dijkstra's algorithm implementation
float Dijkestra(vector<vector<int>> &graph, int src){


    int v = graph.size();

    vector<int> data(v,INT_MAX); // Distance array initialized with infinity values
    data[src] = 0; // Distance from source vertex to itself is set to 0
    
    vector<bool> isVisit(v,false);   // Visited array to track visited vertices

    for(int i =0;i<v;i++){
        int u = getMinimum(data,isVisit);
        isVisit[u] = true;     // Distance from source vertex to itself is set to 0

        // Assign Values according to the algorithm --- 
        for(int j=0;j<v;j++){
            int value = graph[u][j] + data[u];
            if(isVisit[j] == false  && graph[u][j] != 0 && data[j]>=value ){
                data[j] = value;
            }
        }

    }
    printOutput(data,src);  // Print the shortest path distances from the source vertex
    float avg_time = calculateAvgTime(data,src);
    return avg_time;

}

// Function to print the output of the shortest paths
void printOutput(vector<int> &data,int src){
    cout<<"Solutions SSSP : "<<endl;
    for(int i=0;i<data.size();i++){
        cout<<"City "<<src<<" to City "<<i<< " is  "<<data[i]<<endl;
    }
}


// Function to calculate the average time from the data array
float calculateAvgTime(vector<int> &data,int src){
    int sum = 0;
    for(int time : data){
        sum += time;
    }
    float avg_time  = (float) sum/(data.size()-1);
    cout<<endl;
    cout<<"Average Time from City "<<src <<" : "<<avg_time<<endl;
    return avg_time;
}



int main(){

    vector<vector<int>> graph = { { 0,10,0,0,15,5 },
                        { 10,0,10,30,0,0 },
                        { 0,10,0,12,5,0},
                        { 0,30,12,0,0,20},
                        { 15,0,5,0,0,0},
                        { 5,0,0,20,0,0} };

    vector<float> Avg_times;
    float minimum = INT_MAX;

    for(int i=0;i<graph.size();i++){
        float val = Dijkestra(graph,i);
        Avg_times.push_back(val);
        if(minimum>val){
            minimum = val;
        }
    }
    cout<<"=========== Best Cities =========================="<<endl;
    for(int i=0;i<Avg_times.size();i++){
        if(Avg_times[i]==minimum){
            cout<<"Best City build hospital : "<< i<<endl;
        }
    }


    return 0;
}

