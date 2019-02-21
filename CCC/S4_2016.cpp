#include <vector>
#include <stdio.h>

std::vector<std::vector<int> > counts;
std::vector<int> rice_balls;
int total_balls;
 
int can_combine_in_range(int x, int y) 
{
    return x == y ? true : counts[x][y] != -1;
}

int get_count_of_range(int x, int y)
{
    return x == y ? rice_balls[x] : counts[x][y]; 
}

void add_to_cache(int x, int y, int value)
{
    counts[x][y] = value;
}

int search_between_two_blocks(int x, int y)
{
    for (int z = x + 1; z < y + 1; ++z)
    {
        int end_index = z - 1;
        if (!can_combine_in_range(x, end_index)) continue;
        if (!can_combine_in_range(z, y)) continue;
        
        int first_count = get_count_of_range(x, end_index);
        int last_count = get_count_of_range(z, y);
        if (first_count != last_count) continue;
        
        int count = first_count + last_count;
        add_to_cache(x, y, count);
        
        return true;
    }
    
    return false;
}

void search_between_three_blocks(int x, int y)
{
    for (int z = x + 1; z < y; ++z)
    {
        int end_index = z - 1;
        if (!can_combine_in_range(x, end_index)) continue;
        
        int first_count = get_count_of_range(x, end_index);
        for (int last_start_index = z + 1; last_start_index < y + 1; ++last_start_index)
        {
            int z_end = last_start_index - 1;
            if (!can_combine_in_range(z, z_end)) continue;
            if (!can_combine_in_range(last_start_index, y)) continue;
            
            int last_count = get_count_of_range(last_start_index, y);
            if (first_count != last_count) continue;
            
            int middle_count = get_count_of_range(z, z_end);
            int count = first_count + middle_count + last_count;
            
            add_to_cache(x, y, count);
            return;
        }
    }
}

int find_largest()
{
    int max = 0;
    for (int i = 0; i < total_balls; ++i)
    {
        for (int j = 0; j < total_balls; ++j)
        {
            max = std::max(max, get_count_of_range(i, j));
        }
    }
    
    return max;
}

int main() 
{
    scanf("%d", &total_balls);
    
    int ball;
    for (int i = 0; i < total_balls; ++i)
    {
        scanf("%d", &ball);
        rice_balls.push_back(ball);
        
        std::vector<int> row;
        for (int j = 0; j < total_balls; ++j)
        {
            row.push_back(-1);
        }
        
        counts.push_back(row);
    }
    
    for (int i = 2; i < total_balls + 1; ++i)
    {
        int max_start = total_balls - i + 1;
        for (int j = 0; j < max_start; ++j)
        {
            int k = j + i - 1;
            if (search_between_two_blocks(j, k)) continue;
            if (i > 2)
            {
                search_between_three_blocks(j, k);
            }
        }
    }
    
    printf("%d\n", find_largest());
}