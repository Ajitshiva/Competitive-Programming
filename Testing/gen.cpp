#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct Range
{
	array<int, 2> n; // Size of an array
	array<int, 2> a; // Range of an each elment in an array
	Range()
	{
		// Size of an array
	    this->n[0] = 1; // Lower Bound of N
	    this->n[1] = 10; // Upper Bound of N
	    
	    // Range of an each element in an array
	    this->a[0] = 1; // Lower Bound of A[i]
	    this->a[1] = 1000; // Upper Bound of A[i]
	}
};
Range range;
int rnd(array<int, 2> range){
    return range[0] + rand() % (range[1] - range[0] + 1);
}
void generateArray()
{
	int n = rnd(range.n);
	cout << n << endl;
	for(int i = 0; i < n; i++)
	{
		cout << rnd(range.a) << ' ';
	}
	cout << endl;
}
int ran(int l, int r)
{
    return l + (rand() % (r - l + 1));
}
// Function to Generate Tree
void generateTree()
{
 	int n = rnd(range.n);
 	cout << n << endl;
    int length = n - 2;
    int prufer[length];
 
    // Loop to Generate Random Array
    for (int i = 0; i < length; i++)
    {
        prufer[i] = ran(0, length) + 1;
    }
    int vertices = length + 2;
    int vertex_set[vertices];
 
    for (int i = 0; i < vertices; i++)
        vertex_set[i] = 0;
 
    for (int i = 0; i < vertices - 2; i++)
        vertex_set[prufer[i] - 1] += 1;
 
 
    int j = 0;
 
    for (int i = 0; i < vertices - 2; i++)
    {
        for (j = 0; j < vertices; j++)
        {
 
            if (vertex_set[j] == 0)
            {
 
                vertex_set[j] = -1;
                cout<< (j + 1) << " " << prufer[i] << endl;
                vertex_set[prufer[i] - 1]--;
                break;
            }
        }
    }
 
    j = 0;
 
    for (int i = 0; i < vertices; i++)
    {
        if (vertex_set[i] == 0 && j == 0)
        {
 
            cout << (i + 1) << ' ';
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1)
            cout << (i + 1) << endl;
    }
}

signed main(int argc, char * argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    generateArray();
    // generateTree();
}
