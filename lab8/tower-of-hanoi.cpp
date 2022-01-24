#include <iostream>
using namespace std;

int count = 1;
void towerOfHanoi(int height, char source, char aux, char dest)
{
    if (height == 1)
    {
        cout << count<<") Moved disk from: " << source << " to dest: " << dest << endl;
        count++;
        return;
    }
    towerOfHanoi(height - 1, source, dest, aux);
    // move last disk to destination rod
    cout << count<<") Moved disk from: " << source << " to dest: " << dest << endl;
    count++;
    towerOfHanoi(height-1,aux,source,dest);
}

int main()
{
    towerOfHanoi(5, 'A', 'B', 'C');
    return 0;
}