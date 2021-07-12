# SMS project

SMSStore = []
#class definition starts below
class SMSMessage:

    def __init__(self, hasBeenRead, messageText, fromNumber):
    #initialization of  the instance variables
        global SMSStore
        self.hasBeenRead = hasBeenRead
        self.messageText = messageText
        self.fromNumber = fromNumber

    def mark_as_read(self):
        self.hasBeenRead = bool(True)

#methods being implemented
    def add_sms(self, smses):
        for number in range(smses):
            source_number = int(input("please enter source number..."))
            message_body = str(input("please enter message body..."))
            new_message = (source_number, message_body)
            SMSStore.append(new_message)
            return print(SMSStore)
#get methods implementations
    def get_count(self):
        return print(SMSMessage.count())

    def get_message(self):
        return print(len(SMSStore))

    def get_unread_messages(self):
         pass


no_1 = SMSMessage(False, "Hello", "0643431281")
print(no_1.get_smsmessage())
no_2 = SMSMessage(False, "WYD", "0604204078")
print(no_2.get_smsmessage())
no_3 = SMSMessage(False, "how are you?", "0714171229")
print(no_3.get_smsmessage())



userChoice="None"

while userChoice != "quit":
        userChoice = input("what would you like to do -read/send/quit?")
        if userChoice == "read":
            SMSStore.get_count()
        elif userChoice=="send":
            smses = int(input("number of smses to be added"))
            SMSMessage.add_sms(smses)
        #exit the prompt if option says so
        elif userChoice=="quit":
         print("Goodbye")
        else:
                print("oops - wrong input")















