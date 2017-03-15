graph = {1: set([2, 3]),
         2: set([4, 5]),
         3: set([6]),
         4: set([7]),
         5: set([7]),
         6: set([5, 7]),
         7: set([])}

def dfs(graph, root, target, path=None):
    if path is None:
        path = [root]
    if root == target:
        yield path
    for i in [x for x in graph[root] if x not in path]:
        for each_path in dfs(graph, i, target, path + [i]):
            yield each_path

print(list(dfs(graph, 1, 7)))