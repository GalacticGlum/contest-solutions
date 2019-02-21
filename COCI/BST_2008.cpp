#include<map>
#include <stdio.h>
#include <iostream>
int main()
{
  std::map<int, int> m;
  
  int n, x;
  scanf("%d", &n);

  long long count = 0;

  while(n--)
  {
    scanf("%d", &x);
    auto r = m.lower_bound(x);

    int d = 0;

    if(r != m.end())
      d = r->second + 1;

    if(r != m.begin()) {
        std::reverse_iterator<std::map<int,int>::iterator> itr(r);
        d = std::max(d, itr->second + 1);
    }

    m[x] = d;
    count += d;
    
    std::cout << count << "\n";
  }

  return 0;
}
