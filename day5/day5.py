

def getSeedListFromLine(seedsline):
    key, value = seedsline.split(":")
    print("key: ", key)
    print("value: ", value)
    seeds_list = value.strip().split(" ")
    seeds_list = list(filter(None, seeds_list))
    seeds_list = [int(string) for string in seeds_list] 
    
    print("Seeds: ", seeds_list)
    return seeds_list

def populateMapWithEntry(oneline, newList):
    mapEntries = oneline.strip().split(" ")
    mapEntries = list(filter(None, mapEntries))
    mapEntries = [int(string) for string in mapEntries] 

    newList.append(mapEntries)

def findNumInList(num, list):
    #print ("num: ", num, "list ", list)
    for x in list:
        if num >= x[1] and num < x[1]+x[2]:
            #print (num, " is in ", x, "with a value of", x[0] + (num - x[1]))
            return x[0] + (num - x[1])
    return num

def findLocation(seedNum, mainlist):
    print ("Checking for seednum: ", seedNum)
    for listtosearch in range(7):
        seedNum = findNumInList(seedNum, mainlist[listtosearch])
    
    print ("Location: ", seedNum)
    print("-------------------")
    return seedNum


def part1():
    testFile = "./day5input.txt"
    f = open(testFile, "r")
    totalSum = 0
    seeds_list= []

    seedsline = f.readline()
    seeds_list = getSeedListFromLine(seedsline)

    _ = f.readline()
    # of lists = 7
    mainlist = []

    for x in range(7):
        newList = []

        # Skip line for name of list
        _ = f.readline()

        for oneline in f:
            if oneline.strip() == "":
                break
            populateMapWithEntry(oneline, newList)
        
        newList.sort(key=lambda x: x[1])
        mainlist.append(newList)

    seedLocationList = []
    for seedNum in seeds_list:
        seedLocationList.append(findLocation(seedNum, mainlist))

    print ("seedLocationList", seedLocationList)
    print ("min(seedLocationList)", min(seedLocationList))

def rfindNumInList(num, list):
    #print ("num: ", num, "list ", list)
    for x in list:
        if num >= x[0] and num < x[0]+x[2]:
            #print (num, " is in ", x, "with a value of", x[0] + (num - x[1]))
            return x[1] + (num - x[0])
    return num


def findseednum(locationNum, mainlist):
    print ("Checking for location: ", locationNum)
    for listtosearch in range(7):
        locationNum = rfindNumInList(locationNum, mainlist[6-listtosearch])
    
    print ("SeedNum: ", locationNum)
    print("-------------------")
    return locationNum

def part2():
    testFile = "./day5testinput.txt"
    f = open(testFile, "r")
    totalSum = 0
    seeds_list= []

    seedsline = f.readline()
    seeds_list = getSeedListFromLine(seedsline)
    seedsiter = iter(seeds_list)
    seeds_list = zip(seediter, seediter)
    _ = f.readline()
    # of lists = 7
    mainlist = []
    seeds_list.append(seeds_list)

    for x in range(7):
        newList = []

        # Skip line for name of list
        _ = f.readline()

        for oneline in f:
            if oneline.strip() == "":
                break
            populateMapWithEntry(oneline, newList)
        
        newList.sort(key=lambda x: x[1])
        mainlist.append(newList)

    seedLocationList = []
    for locationList in mainlist[7:]:
        for index in range(seedNumPair[1]):
            seedLocationList.append(findLocation(seedNum, mainlist))

    print ("seedLocationList", seedLocationList)
    print ("min(seedLocationList)", min(seedLocationList))

def main():
    part1()
    # print(part2())

if __name__ == "__main__":
    main()