# this is the sms project
#class definition starts below

class SMSMessage:
    hasBeenRead=False
    messageText= txt
    fromNumber= number
    def __init__(self, hasBeenRead, messageText, fromNumber):
    #initialization of  the instance variables
        self.hasBeenRead = hasBeenRead
        self.messageText = messageText
        self.fromNumber = fromNumber

    def mark_as_read(self):
        if userChoice == read:
            self.hasBeenRead = True

    #instance get method
    def get_smsmessage(self):
        return f'{self.hasBeenRead}.{self.messageText}.{self.fromNumber}'

    #creating objects for this Sms class / call the method
    no_1 = SMSMessage(False, "Hello", "0643431281")
    print(no_1.get_smsmessage())
    no_2 = SMSMessage(False, "WYD", "0604204078")
    print(no_2.get_smsmessage())
    no_3 = SMSMessage(False, "how are you?", "0714171229")
    print(no_3.get_smsmessage())


SMSStore=[]
userChoice=""

    while userChoice != "quit":
        userChoice = raw_input("what would you like to do -read/send/quit?")
        if userChoice == "read":
            messageText.hasBeenRead=True
       # elif userChoice=="send":
         #statements
        #elif userChoice=="quit":
            #statements

    print("Goodbye")
    #else:
    print("oops - wrong input")







