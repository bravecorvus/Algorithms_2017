a, b, c, d, e, f, g, h = range(8)
G = [
    set([b, c, f]),
    set([e]),
    set([d]),
    set([a, h]),
    set([f, g, h]),
    set([b, g]),
    set(),
    set([g])
    ]

def rec_dfs(G, s, S=None):
    if S is None:
        S = set()
    S.add(s)
    for u in G[s]:
        if u in S:
            continue
        rec_dfs(G, u, S)

def iter_dfs(G, s):
    S, Q = set(), []
    Q.append(s)
    while Q:
        u = Q.pop()
        if u in S:
            continue
        S.add(u)
        Q.extend(G[u])
        yield u

def dfs(G, s, pre, post, S=None, t=0):
    if S is None:
        S = set()
    pre[s] = t
    t += 1
    S.add(s)
    for u in G[s]:
        if u in S:
            continue
        t = dfs(G, u, pre, post, S, t)
    post[s] = t
    t += 1
    return t

print(rec_dfs(G, b))