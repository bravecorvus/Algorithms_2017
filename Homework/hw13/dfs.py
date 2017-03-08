class Node:
    def __init__(self, arg):
        self.name = arg[0]
        self.edges = arg[1]
        self.visited = False

    def __str__(self):
        returnlist = []
        returnlist.append("Visited: " + str(self.visited))
        returnlist.append("Name: " + str(self.name))
        returnlist.append("Edges: " + str(self.edges))
        return ' '.join(returnlist)
    def get_name(self):
        return self.name
    def getEdges(self):
        return self.edges
    def setVisitedTrue(self):
        self.visited = True
    def setVisitedFalse(self):
        self.visited = False
    def getVisited(self):
        return self.visited
    # def neighborsisvisited(self, v):
    #     for i in self.edges:
    #         if v == i:
    #             c = i.getEdges()
    #     for i in c:
    #         if i.checkVisited() == False:
    #             return i.get_name()
    #             break


class UndirectedGraph:
    def __init__(self, arg=[]): #List within a list
        self.graphmap = []
        for i in arg:
            x = Node(i)
            self.graphmap.append(x)
    def __str__(self):
        returnmap = []
        for i in self.graphmap:
            returnmap.append(str(i))
        return '\n'.join(returnmap)
    def visited(self, v):
        for i in self.graphmap:
            if v == i.get_name():
                i.setVisitedTrue();
                print(i)
                break;
    def neighborsisvisited(self, v):
        for i in self.graphmap:
            if v == i.get_name():
                c = i.getEdges()
        for i in c:
            if i.getVisited() == False:
                return i.get_name()
                break

def procedure_explore(G, v): 
    G.visited(v)
    for i in G.graphmap:
        G.visited(neighborsisvisited(i.get_name()))

def dfs(G):
    for i in G.graphmap:
        if i.getVisited() == False:
            procedure_explore(G, i.get_name)



inputlist = [["A", ["B", "D"]], ["B", ["A", "E", "F"]], ["C", ["F"]], ["D", ["A", "G"]], ["E", ["B", "I"]], ["F", ["B", "C"]], ["G", ["D", "H"]], ["H", ["G"]], ["I", ["E", "J"]], ["J", ["I"]]]
thegraph = UndirectedGraph(inputlist)
dfs(thegraph)
print(thegraph)