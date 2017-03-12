# Design a linear-time algorithm which, given an undirected graph G and a particular edge e in it, determines whether G has a cycle containing e.
#!/usr/bin/python
def dfs_rec(adjLists, visited, v, originroot):
    visited[v] = True
    # print(v, " ", end='')
    for w in adjLists[v]:
        if(not visited[w]):
            dfs_rec(adjLists, visited, w, originroot)
        if w == originroot:
            print("Loop Present")
 
             
def dfs(adjLists, s):
    visited = []
    n = len(adjLists)
    originroot = s
    for i in range(n):
        visited.append(False)
    dfs_rec(adjLists, visited, s, originroot)


representation = [[1, 2], [0, 2], [0, 1, 3], [2]]
dfs(representation, 1)