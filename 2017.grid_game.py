def simulate_max_path(grid):
    i = 0
    j = 0
    total = 0
    while i != 1 or j != len(grid[0]):
        total += grid[i][j]
        grid[i][j] = 0
        if i==1:
            j += 1
        else:
            sum_top = sum(grid[i][j+1:]) + grid[1][-1]
            sum_bottom = sum(grid[i+1][j:])
            if (sum_top > sum_bottom):
                j += 1
            elif (sum_bottom > sum_top and grid[i][j+1] > grid[i+1][j]):
                j += 1
            else:
                i += 1
    return total

"""
grid = [[20, 3,20,17, 2,12,15,17, 4,15],
        [20,10,13,14,15, 5, 2, 3,14, 3]]
print(sum(grid[0]) + sum(grid[1]))   # 224 
print(sum(grid[0])) # 125
print(sum(grid[1])) # 99
"""
grid = [[10,12,14,19,19,12,19, 2,17],
        [20, 7,17,14, 3, 1, 1,17,12]]
# robot 1
simulate_max_path(grid) # 128 should be 161

# robot 2
print(simulate_max_path(grid))