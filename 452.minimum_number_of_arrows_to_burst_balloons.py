def intersec(first: list, second: list):
    min_begin, max_begin = sorted([first[0], second[0]])
    min_end, max_end = sorted([first[1], second[1]])
    if min_end < max_begin:
        return None
    return [max_begin, min_end]


def findMinArrowShots(points: list) -> int:
    intersections = [points[0]]
    for i in range(1, len(points)):
        found = False
        j = 0
        while not found and j < len(intersections):
            inter = intersec(points[i], intersections[j])
            if inter:
                intersections[j] = inter
                found = True
            j+=1
        if not found:
            intersections.append(points[i])
                
    return len(intersections)


points = [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]

print(findMinArrowShots(points))