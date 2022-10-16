import re
import string

#Takes the items in the file and puts them into a dictionary
#Outputs how many of each item was sold
def displayItemsPurchased():
    #Open the file containing items purchased
    items = open("CS210_Project_Three_Input_File.txt")

    #Create a list for the items purchased
    itemCount = dict()

    #Check the lines in the file
    for item in items:
        #Strips newline character
        item = item.strip()

        #Check how many times an item shows up in the file
        if item in itemCount:
            itemCount[item] = itemCount[item] + 1
        else:
            itemCount[item] = 1

    #Print 
    for x in list(itemCount.keys()):
        print("{}: {}".format(x, itemCount[x]))

    #Close the file
    items.close()

#Outputs how many times a specific item was sold
def displaySpecificItemPurchased(item):
    #Initializes the item count
    itemCount = 0

    #Converts to lower case
    item = item.lower()

    #Opens the file
    items = open("CS210_Project_Three_Input_File.txt", "r")

    for itemCheck in items:
        #Removes newline character to changes to lower for better comparison
        itemCheck = itemCheck.strip().lower()

        #If the item the user entered matches the item in the list, increment by one
        if(item == itemCheck):
            itemCount += 1

    #Close the file and return the item count
    return itemCount
    items.close()
    
#Opens the CS210_Project_Three_Input_File.txt and reads the data
#Compiles the information and inputs the data to the frequency.dat file by writing each unique item name
#and how many times the item has been purchased
def displayItemsPurchasedHistogram():
    #Open the file containing items purchased and create frequency.dat
    items = open("CS210_Project_Three_Input_File.txt", "r")
    frequency = open("frequency.dat", "w")

    #Create a list for the items purchased
    itemCount = dict()

    #Check the lines in the file
    for item in items:
        #Strips newline character
        item = item.strip()

        #Check how many times an item shows up in the file and increments if more than once
        if item in itemCount:
            itemCount[item] = itemCount[item] + 1
        else:
            itemCount[item] = 1

    #Writes the item name and their values to frequency.dat
    for x in list(itemCount.keys()):
        frequency.write(str(x) + " " + str(itemCount[x]))

    #Close the files
    items.close()
    frequency.close()