#!/usr/bin/env python
# coding: utf-8

# # Intelligent Agents: Vacuum-cleaner World
# 
# Implement a simulator environment for a vacuum-cleaner world and a set of intelligent agents.
# 
# ## PEAS description
# 
# __Performance Measure:__ Each action costs 1. The performance is measured as the sum of the cost to clean the whole environment.
# 
# __Environment:__ A room with $n \times n$ squares where $n = 5$. Dirt is randomly placed on each square with probability $p = 0.2$. For simplicity, you can assume that the agent knows the size of the layout of the room (i.e., it knows n and where it starts).
# 
# __Actuators:__ The agent can `clean` the current square or move to an adjacent square by going `north`, `east`, `west`, or `south`.
# 
# __Sensors:__ Four bumper sensors, one for north`, `east`, `west`, and `south`; a dirt sensor reporting dirt in the current square.  
# 
# The easiest implementation for the environment is to hold an 2-dimensional array to represent if squares are clean or dirty and to call the agent function in a loop untill all squares are clean or a predefined number of steps have been reached.
# 
# ## Define the agent program for a simple randomized agent
# 
# The agent program is a function that gets sensor information (the current percepts) as the arguments. The arguments are:
# 
# * A dictonary with boolean entries for the for bumper sensors `north`, `east`, `west`, `south`; not specified bumpers are assumed to be `False`. E.g., if the agent is on the north-west corner, `bumpers` gets `{"north" : True, "west" : True}` or if the agent is not close to a border then it gets `{}`.
# * The dirt sensor produces a boolean.
# 
# The agent returns the chosen action as a string.
# 
# Here is an example implementation for the agent program of a simple randomized agent:  

# In[1422]:


from numpy import random

actions = ["north", "east", "west", "south", "suck"]


def simple_randomized_agent(bumpers, dirty):
    return random.choice(actions)


# In[1423]:


simple_randomized_agent({"north" : True}, True)


# ## Simple environment example
# 
# The environment is infinite in size (bumpers are always `False`) and every square is dirty. We run the agent for 10 times steps.

# In[1424]:


for i in range(10):
    print(simple_randomized_agent({"north" : False, "south" : False, "west" : False, "east" : False}, True))


# # Tasks
# 
# _Submission Instructions:_ Use this notebook to prepare your submission. Complete this section with your code and results. You can use Markdown blocks for your description, comments in the code and use mathplotlib to produce charts. If you use external code files then you can include them with 
# 
# ```
# from notebook import psource
# psource("your_file.py")
# ```
# 
# _Note:_ Try to keep the code simple! In this couse, we want to learn about the algorithms and we often do not need to use object-oriented design. 
# 
# 
# ## Task 1: Implement a simulation environment
# 
# Your environment simulator needs to create squares, make some dirty, and proivde the agent function with the sensor inputs. The environment needs to evaluate the performance measure. It needs to track the agent's actions until all dirty squares are clean and count the number of actions it takes the agent to complete the task.
# 
# The simulation environment needs to work with the simple randomized agent program from above.

# In[1429]:


#makes probability of being dirty .2
dirty = [True, True, False, False, False, False, False, False, False, False]

#variables that store the dimensions of the room
global n
n = 5
global size
size = n*n

#creates 2d array
environment = []
for a in range(n):
    environment.append([])

#environment is made up of squares objects
class Square:
    def __init__(self, xCoord, yCoord, isDirty, bumpers):
        self.xCoord = xCoord
        self.yCoord = yCoord
        self.isDirty = isDirty
        self.bumpers = bumpers
        
    #randomizes if square is dirty
    def makeDirty(self):
        self.isDirty = random.choice(dirty)
        
    #triggers bumpers based on location of agent
    def triggerBumpers(self):
        if(self.xCoord == 0):
            if(self.yCoord == 0):
                self.bumpers = {"north" : True, "west" : True}
            elif(self.yCoord == n - 1):
                self.bumpers = {"south" : True, "west" : True}
            else:
                self.bumpers = {"west" : True}
        elif(self.xCoord == n - 1):
            if(self.yCoord == 0):
                self.bumpers = {"north" : True, "east" : True}
            elif(self.yCoord == n - 1):
                self.bumpers = {"south" : True, "east" : True}
            else:
                self.bumpers = {"east" : True}
        elif(self.yCoord == 0):
            if(self.xCoord > 0 and self.xCoord < n - 1):
                self.bumpers = {"north" : True}
        elif(self.yCoord == n - 1):
            if(self.xCoord > 0 and self.xCoord < n - 1):
                self.bumpers = {"south" : True}        

#creates actual environment
#numDirty keeps track of how many dirty squares there are total in the environment
def createSquares():
    global numDirty
    numDirty = 0
    
    #creates environment based on given size
    for i in range(n):
        for j in range(n):
            #initial object with x and y coordinates given by for loop
            #isDirty initialized to false
            #bumpers initialized to none
            obj = Square(i, j, False, {})
            
            obj.makeDirty()
            
            if(obj.isDirty == True):
                numDirty = numDirty + 1
                
            obj.triggerBumpers()
            
            environment[i].append(obj)
            
#create environment            
createSquares()
    
#below code implements random agent
#agent starts in top left corner at [0,0]
global randomX
randomX = 0
global randomY
randomY = 0

#keeps track of total actions it takes to clean room
global numActions
numActions = 0

#algorithm below handles movement of agent
#made sure that agent does not go off map by handling coordinates based on if bumpers were triggered
while(numDirty > 0):
    trackAction = simple_randomized_agent(environment[randomX][randomY].bumpers, environment[randomX][randomY].isDirty)
    #will not print actions for this one, as it makes the pdf 33 pages long:(
    #print(trackAction)
    
    if(trackAction == "suck"):
        if(environment[randomX][randomY].isDirty == True):
            environment[randomX][randomY].isDirty = False
            numDirty = numDirty - 1
            numActions = numActions + 1
            
    elif(trackAction == "north"):
        if(environment[randomX][randomY].bumpers != {"north" : True, "west" : True} and environment[randomX][randomY].bumpers != {"north" : True, "east" : True} and environment[randomX][randomY].bumpers != {"north" : True}):
            randomY = randomY - 1
            numActions = numActions + 1
    
    elif(trackAction == "east"):
        if(environment[randomX][randomY].bumpers != {"north" : True, "east" : True} and environment[randomX][randomY].bumpers != {"south" : True, "east" : True} and environment[randomX][randomY].bumpers != {"east" : True}):
            randomX = randomX + 1
            numActions = numActions + 1
        
    elif(trackAction == "south"):
        if(environment[randomX][randomY].bumpers != {"south" : True, "west" : True} and environment[randomX][randomY].bumpers != {"south" : True, "east" : True} and environment[randomX][randomY].bumpers != {"south" : True}):
            randomY = randomY + 1
            numActions = numActions + 1
        
    elif(trackAction == "west"):
        if(environment[randomX][randomY].bumpers != {"north" : True, "west" : True} and environment[randomX][randomY].bumpers != {"south" : True, "west" : True} and environment[randomX][randomY].bumpers != {"west" : True}):
            randomX = randomX - 1
            numActions = numActions + 1

print("number of actions to clean environment: ", numActions)


# ## Task 2:  Implement a simple reflex agent
# 
# The simple reflex agent randomly walks around but reacts to the bumper sensor by not bumping into the wall and to dirt with sucking.

# In[1426]:


createSquares()

#for some reason, between task1 and task2, all squares were being initialized to clean (isDirty = False)
#even though I instantiate a new environment and even though numDirty is not zero
#this for loop takes numDirty and reallocates which squares are dirty just to take care of this problem
#not my favorite way to solve this problem, but it solves the problem
for x in range(numDirty):
    i = random.randint(0,n-1)
    j = random.randint(0, n-1)
    
    #if the random square is already dirty, find random indexes until find a clean square
    while(environment[i][j].isDirty == True):
        i = random.randint(0,n-1)
        j = random.randint(0, n-1)
        
    environment[i][j].isDirty = True

#assortment of actions that can be randomly selected from 
randomMove = ["north", "east", "west", "south"]
exNMove = ["east", "west", "south"]
exSMove = ["east", "west", "north"]
exEMove = ["south", "west", "north"]
exWMove = ["east", "south", "north"] 
exNWMove = ["east", "south"]
exSWMove = ["east", "north"]
exNEMove = ["west", "south"]
exSEMove = ["west", "north"]

#handles movement of agent
#handles scenarios where if it runs into a wall on the west size, it cannot go west. it can only choose from
#a list of south, east, and north
def simpleReflexAgent(bumpers, dirty):
    if(dirty == True):
        return "suck"
    if(bumpers == {"north" : True, "west" : True}):
        return random.choice(exNWMove)
    elif(bumpers == {"west" : True}):
        return random.choice(exWMove)
    elif(bumpers == {"south" : True, "west" : True}):
        return random.choice(exSWMove)
    elif(bumpers == {"north" : True, "east" : True}):
        return random.choice(exNEMove)
    elif(bumpers == {"east" : True}):
        return random.choice(exEMove)
    elif(bumpers == {"south" : True, "east" : True}):
        return random.choice(exSEMove)
    elif(bumpers == {"north" : True}):
        return random.choice(exNMove)
    elif(bumpers == {"south" : True}):
        return random.choice(exSMove)
    else:
        return random.choice(randomMove)

#starts at square [0,0]
global randomX
randomX = 0
global randomY
randomY = 0

#keeps track of number of actions
global numActions
numActions = 0

#handles movement of agent in environment
while(numDirty > 0):
    trackAction = simpleReflexAgent(environment[randomX][randomY].bumpers, environment[randomX][randomY].isDirty)
    print(trackAction)
    
    if(trackAction == "suck"):
        environment[randomX][randomY].isDirty = False
        numDirty = numDirty - 1
            
    elif(trackAction == "north"):
        randomY = randomY - 1
    
    elif(trackAction == "east"):
        randomX = randomX + 1
        
    elif(trackAction == "south"):
        randomY = randomY + 1
        
    elif(trackAction == "west"):
        randomX = randomX - 1
    
    numActions = numActions + 1

print("number of actions to clean environment: ", numActions)


# ## Task 3: Implement a model-based reflex agent 
# 
# This agent keeps track of the location and remembers where it has cleaned. Assume the agent knows how many squares the room has and where it starts. It can now use more advanced navigation.
# 
# _Note on implementing the state:_ You can use a global variable. In Python, you have to use the keyword `global` in your function for this to work (see: https://www.programiz.com/python-programming/global-keyword). Alternatively, you can define a class for your agent with a member variable for the state and a function for the agent program (see: https://www.w3schools.com/python/python_classes.asp). 
# 
# Describe how your agent will perform 
# * if it is put into a larger room, 
# * if the room contains obstacles, or 
# * if it starts in a random square.

# ### Description of Agent Performance Based on Three Scenarios Given Above
# 
# The strategy of this agent is essentially to go wall to wall (and down when it reaches a wall) until the entire environment has been traveled. Therefore, if placed in a larger room, this agent's performance will increase linearly. If the room that the agent is placed in contains obstacles, the agent will not handle them efficiently (and not at all really). There are no conditions coded into this agent that use bumpers, therefore, if an agent runs into an obstacle, it's wheels will most likely keep turning (although it will not be able to move anywhere) until it reaches the range as laid out in the for loop. It will then go south but then will most likely run into the same problem when it experiences a wall because of dimensions of the room are offset due to the obstacle's interference. In the same way, if the agent starts in a random square, like the middle of the room, for example, it will run into the wall and continue turning its wheels until the range limit has been reached. And then it will go south and carry on as usual. However, the size incrementer does not account for this scenario either. Further, the agent will not be able to backtrack to the squares behind it or above it as that is not the way it is programmed. 

# In[1427]:


createSquares()

#so, like before, weird stuff was happening with the environment, where sometimes when I created a new environment
#dirty squares would show up and other times all squares isDirty = False although numDirty was never zero
#so, again, a brute force solution
#i initialize all squares to clean and then carry out the for loop like above where I reallocate dirty squares
for i in range(n):
    for j in range(n):
        environment[j][i].isDirty = False

for x in range(numDirty):
    i = random.randint(0,n-1)
    j = random.randint(0, n-1)
    
    #if the random square is already dirty, find random indexes until find a clean square
    while(environment[i][j].isDirty == True):
        i = random.randint(0,n-1)
        j = random.randint(0, n-1)
        
    environment[i][j].isDirty = True
    
#2d array that keep track of squares the agent cleans
squaresCleaned = []
for a in range(numDirty):
    squaresCleaned.append([])

#model-based reflex agent class
class modelBasedReflexAgent:
    def __init__(self, xLocation, yLocation, index, cleanedSquares, numActions):
        self.xLocation = xLocation
        self.yLocation = yLocation
        self.index = index
        self.cleanedSquares = cleanedSquares
        self.numActions = numActions
        
    #keeps track of agent's current location
    def storeLocation(self, xLocation, yLocation):
        self.xLocation = xLocation
        self.yLocation = yLocation
        
    #takes coordinates of square that agent cleaned and stores it in 2d array
    def addToCleanSquares(self, xLocation, yLocation):
        self.cleanedSquares[self.index].append(xLocation)
        self.cleanedSquares[self.index].append(yLocation)
        
    #east movement
    def goEast(self):
        print("east")
        self.xLocation = self.xLocation + 1
        self.numActions = self.numActions + 1
        self.storeLocation(self.xLocation, self.yLocation)
    
    #west movement
    def goWest(self):
        print("west")
        self.xLocation = self.xLocation - 1
        self.numActions = self.numActions + 1
        self.storeLocation(self.xLocation, self.yLocation)
        
    #south movement
    def goSouth(self):
        print("south")
        self.yLocation = self.yLocation + 1
        self.numActions = self.numActions + 1
        self.storeLocation(self.xLocation, self.yLocation)
    
    #method that is called to actually clean environment
    def clean(self):
        #keeps track of if agent should be going east or west
        global isEast
        isEast = True
        
        #keeps track of how many squares the agent has cleaned
        global sizeIterator
        sizeIterator = 1
        
        #this while loop will conduct until sizeIterator equals the given size of the environment
        #again, another weird thing. the loop carries out until the sizeIterator is one value greater than
        #the size of the environment, which I handle in a brute force manner, as you will see below
        while (sizeIterator < size):
            #travel horizontally for given size
            for i in range(n):
                #handling if square is dirty
                if (environment[self.xLocation][self.yLocation].isDirty == True):
                        environment[self.xLocation][self.yLocation].isDirty = False
                        print("suck")
                        self.numActions = self.numActions + 1
                        self.addToCleanSquares(self.xLocation, self.yLocation)
                        self.index = self.index + 1
                
                #while not at the wall, continue to go east or west
                if(i != 4):
                    if(isEast == True):
                        self.goEast()
                        sizeIterator = sizeIterator + 1
                    else:
                        self.goWest()
                        sizeIterator = sizeIterator + 1
            
            #if it was going east, now go west and vice versa
            if(isEast == True):
                isEast = False
            else:
                isEast = True
                       
            #goes south once to go to next row after wall has been reached
            self.goSouth()
            sizeIterator = sizeIterator + 1
                
        print("number of actions to clean environment: ", self.numActions - 1)

#agent starts at square [0,0]
global xCoordinate
xCoordinate = 0
global yCoordinate
yCoordinate = 0

#keeps track of index in squaresCleaned array
global index
index = 0

#keeps track of number of actions
numActions = 0

#creates agent object and call clean method
agent = modelBasedReflexAgent(xCoordinate, yCoordinate, index, squaresCleaned, numActions)
agent.clean()


# ## Task 4: Simulation study
# 
# Compare the performance of the agents using different size environments. E.g., $5 \times 5$, $10 \times 10$ and
# $100 \times 100$. Use at least 100 random runs for each.

# ### Description of Agent Performance over 100 Random Runs
# 
# As is shown below, the model-based reflex agent is the most efficient when compared to the performance of the simple randomized agent and the simple reflex agent. This remains consistent throughout the three sizes of the room - 5x5, 10x10, 100x100. As the room size increased, the model-based agent's performance increased rather linearly and, in general, its performance was consistent and did not have any outliers. The simple reflex agent's peformance grew more sporatic as the room size increased although it's performance was rather linear as well. In general, the simple reflex agent's performance was a little inconsistent; some runs were efficient while others were extremely inefficent, as is seen in the spikes in its performance in the graphs below. The worst performing agent would be the simple randomized agent. All around, its performance in each room was varied and inconsistent and, as the room size increased, so did the inconsistency. This inconsistency is especially emphasized in the graph considering the 100x100 size environment. One of its lower performances where the total number of actions to clean the room was around 400,000, while one of its highest performances was around 1,200,000 total numbers of actions. This demonstrates the inconsistency of this agent as well as how much its performance varied.

# In[798]:


import matplotlib.pyplot as plt

plt.plot(x1, y1, label = "simple randomized agent")
plt.plot(x2, y2, label = "simple reflex agent")
plt.plot(x3, y3, label = "model-based reflex agent")

plt.xlabel('number of runs')
plt.ylabel('number of actions')

plt.title('100 Random Runs of Three Different Agents at 5x5 Size Environment')

plt.legend()

plt.show


# In[799]:


plt.plot(x4, y4, label = "simple randomized agent")
plt.plot(x5, y5, label = "simple reflex agent")
plt.plot(x6, y6, label = "model-based reflex agent")

plt.xlabel('number of runs')
plt.ylabel('number of actions')

plt.title('100 Random Runs of Three Different Agents at 10x10 Size Environment')

plt.legend()

plt.show


# In[1421]:


plt.plot(x7, y7, label = "simple randomized agent")
plt.plot(x8, y8, label = "simple reflex agent")
plt.plot(x9, y9, label = "model-based reflex agent")

plt.xlabel('number of runs')
plt.ylabel('number of actions (in 100,000s)')

plt.title('100 Random Runs of Three Different Agents at 100x100 Size Environment')

plt.legend()

plt.show


# ## Bonus tasks
# 
# * __Obstacles:__ Add random obstacle squares that also trigger the bumper sensor. The agent does not know where the obstacles are. Observe how this changes the performance of the three implementations.
# * __Unknown environment with obstacles:__ Implement an agent for an environment where the agent does not know how large the environment is (we assume it is rectangular), where it starts or where the obstacles are. An option would be to always move to the closest unchecked/uncleaned square.
# * __Utility-based agent:__ Change the environment, so each square has a fixed probability of getting dirty again. We assume the agent has learned this information over time. For the implementation, we give this information to the agent as a 2-dimensional array of probabilities  Cleaning one dirty square produces a utility of 1. Implement a utility-based agent that maximizes the expected utility over one full charge which lasts for 10000 time steps. This is very tricky!

# In[ ]:


# Your code goes here

