#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

struct Node{
    vector<Node*> children;
    int height=1;
};

void BFS(Node* head){
    std::ios_base::sync_with_stdio(0);
    Node* queue[10050];
    int top=0, tail=0, maxheight=0;
    queue[tail]=head;
    tail++;
    while(tail>top){
        Node* cur=queue[top];
        top++;
        for(int i=0; i<cur->children.size(); i++){
            cur->children[i]->height = cur->height+1;
            maxheight=cur->children[i]->height;
            queue[tail]=cur->children[i];
            tail++;
        }
    }
    return maxheight;
}



int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return BFS();
}
