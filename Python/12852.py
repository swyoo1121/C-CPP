import sys

def solution():
    visited = []
    queue = [[N, [N]]]

    while queue:
        number, path = queue.pop(0)
        if number == 1:
            print(len(path) - 1)
            print(" ".join(map(str, path)))
            break

        if number not in visited:
            visited.append(number)
            if number % 3 == 0:
                queue.append([number // 3, path + [number // 3]])
            if number % 2 == 0:
                queue.append([number // 2, path + [number // 2]])
            queue.append([number - 1, path + [number - 1]])


N = int(input())
solution()