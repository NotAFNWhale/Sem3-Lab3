#include <cstdlib>
#include <iostream>
#include <string>
#include "tests.h"
#include "graph.h"

using namespace std;

Graph<int>* GetDefaultGraph()
{
    Graph<int> *gr = new Graph<int>(8);
    gr->ChangeEdge(0, 1, 5);
    gr->ChangeEdge(0, 2, 9);
    gr->ChangeEdge(1, 2, 3);
    gr->ChangeEdge(1, 4, 1);
    gr->ChangeEdge(2, 3, 2);
    gr->ChangeEdge(3, 4, 5);
    gr->ChangeEdge(3, 7, 4);
    gr->ChangeEdge(4, 5, 9);
    gr->ChangeEdge(1, 5, 8);
    gr->ChangeEdge(5, 6, 3);
    gr->ChangeEdge(6, 7, 4);
    return gr;
}
DirGraph<int>* GetDefaultDirGraph()
{
    DirGraph<int> *gr = new DirGraph<int>(8);
    gr->ChangeEdge(0, 1, 5);
    gr->ChangeEdge(0, 2, 9);
    gr->ChangeEdge(1, 2, 3);
    gr->ChangeEdge(1, 4, 1);
    gr->ChangeEdge(2, 3, 2);
    gr->ChangeEdge(3, 4, 5);
    gr->ChangeEdge(3, 7, 4);
    gr->ChangeEdge(4, 5, 9);
    gr->ChangeEdge(1, 5, 8);
    gr->ChangeEdge(5, 6, 3);
    gr->ChangeEdge(6, 7, 4);
    return gr;
}
void EditGraph(Graph<int> *gr)
{
    int act = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    while(true)
    {
        cout << "Adjacency matrix:" << endl;
        cout << gr->AdjMatr();
        cout << endl;
        cout << "1.Add/change an edge" << endl;
        cout << "2.Continue" << endl;
        cout << "\t";
        cin >> act;
        switch(act)
        {
            case 1:
                cout << "Input first vertex: ";
                cin >> vert1;
                cout << "Input second vertex: ";
                cin >> vert2;
                cout << "Input weight: ";
                cin >> weight;
                gr->ChangeEdge(vert1, vert2, weight);
                break;
            default:
                return;
        }
    }
}
void EditDirGraph(DirGraph<int> *gr)
{
    int act = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    while(true)
    {
        cout << "Adjacency matrix:" << endl;
        cout << gr->AdjMatr();
        cout << endl;
        cout << "1.Add/change an edge" << endl;
        cout << "2.Continue" << endl;
        cout << "\t";
        cin >> act;
        switch(act)
        {
            case 1:
                cout << "Input first vertex: ";
                cin >> vert1;
                cout << "Input second vertex: ";
                cin >> vert2;
                cout << "Input weight: ";
                cin >> weight;
                gr->ChangeEdge(vert1, vert2, weight);
                break;
            default:
                return;
        }
    }
}

void interfaceGraph()
{
    int num = 0;
    int act = 0;
    int i = 0;
    int j = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    Graph<int> *gr;
    ArraySequence<int> *path;

    cout << "1.Default graph" << endl;
    cout << "2.Manual input" << endl;
    cout << "3.Quit" << endl;
    cout << "\t";
    cin >> act;
    switch (act)
    {
        case 1:
            gr = GetDefaultGraph();
            break;
        case 2:
            cout << "Input vertexes number: ";
            cin >> num;
            gr = new Graph<int>(num);
            break;
        default:
            return;
    }

    EditGraph(gr);
    
    while(true)
    {
        cout << "1.Find path" << endl;
        cout << "2.Add/change an edge" << endl;
        cout << "3.Quit" << endl;
        cout << "\t";
        cin >> act;
        switch(act)
        {
            case 1:
                cout << "Input start: ";
                cin >> i;
                cout << "Input finish: ";
                cin >> j;
                path = gr->GetPath(i, j);

                cout << "The shortest path: ";
                
                for (int i = 0; i < path->GetSize(); i++)
                    cout << path->Get(i) << " ";
                cout << endl;
                cout << "Weight: " << gr->GetPathWeight(path) << endl;
                break;

            case 2:
                cout << "Input first vertex: ";
                cin >> vert1;
                cout << "Input second vertex: ";
                cin >> vert2;
                cout << "Input weight: ";
                cin >> weight;
                
                gr->ChangeEdge(vert1, vert2, weight);
                
                cout << "Adjacency matrix:" << endl;
                cout << gr->AdjMatr();
                cout << endl;
                break;
            default:
                return;
        }
    }
}
void interfaceDirGraph()
{
    int num = 0;
    int act = 0;
    int i = 0;
    int j = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    DirGraph<int> *gr;
    ArraySequence<int> *path;
    ArraySequence<int> *ts;

    while(true)
    {
        cout << "1.Default graph" << endl;
        cout << "2.Manual input" << endl;
        cout << "3.Quit" << endl;
        cout << "\t";
        cin >> act;

        switch (act)
        {
            case 1:
                gr = GetDefaultDirGraph();
                break;
            case 2:
                cout << "Input vertexes number" << endl;
                cin >> num;
                gr = new DirGraph<int>(num);
                break;
            default:
                return;
        }

        EditDirGraph(gr);
        
        while(true)
        {
            cout << "1.Find path" << endl;
            cout << "2.Topological Sort" << endl;
            cout << "3.Add/change an edge" << endl;
            cout << "4.Quit" << endl;
            cout << "\t";
            cin >> act;
            
            switch(act)
            {
                case 1:
                    cout << "Input start: ";
                    cin >> i;
                    cout << "Input finish: ";
                    cin >> j;

                    path = gr->GetPath(i, j);
                    
                    cout << "The shortest path: ";
                    
                    for (int i = 0; i < path->GetSize(); i++)
                        cout << path->Get(i) << " ";
                    cout << endl;
                    cout << "Weight: " << gr->GetPathWeight(path) << endl;
                    break;

                case 2:
                    ts = gr->GetTopologicalSort();
                    cout << "The Topological sort:" << endl;
                    
                    for (int i = 0; i < ts->GetSize(); i++)
                        cout << ts->Get(i) << " ";
                    
                    cout << endl;
                    break;
                case 3:
                    cout << "Input first vertex: ";
                    cin >> vert1;
                    cout << "Input second vertex: ";
                    cin >> vert2;
                    cout << "Input weight: ";
                    cin >> weight;
                    gr->ChangeEdge(vert1, vert2, weight);
                    cout << "Adjacency matrix:" << endl;
                    cout << gr->AdjMatr();
                    cout << endl;
                    break;
                default:
                    return;
            }
        }
    }
}

int main()
{
    int act = 0;

    cout << "1.Work with directed graph" << endl;
    cout << "2.Work with undirected graph" << endl;
    cout << "3.Run tests" << endl;
    cout << "\t";
    cin >> act;

    switch(act)
    {
        case 1:
            interfaceDirGraph();
            break;
        case 2:
            interfaceGraph();
            break;
        case 3:
            tests();
            break;
        default:
            break;
    }

	return 0;
}