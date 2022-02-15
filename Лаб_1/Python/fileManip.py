from asyncore import write


def get_input_data(input_file_name):
    print("Enter your text (To stop enter Ctrl + W):")
    text = []
    line = input()
    while line != '\x17':
        text.append(line)
        line = input()
    return text

def display_text(msg, text):
    print(msg)
    for i in text:
        print(i)
        
def write_to_file(text, input_file_name):
    with open(input_file_name, 'w') as file:
        file.write("\n".join(text))

def display_data(msg, file_name):
    print(msg)
    with open(file_name) as file:
        for line in file:
            print(line, end = '')
    print()

def sort_text(text):
    for line in text:
        for strInd in range(len(text)-1):
            if len(text[strInd]) > len(text[strInd+1]):
                text[strInd], text[strInd+1] = text[strInd+1], text[strInd]

def add_len(text):
    for strInd in range(len(text)):
        new_line = text[strInd] + "<-" + str(len(text[strInd]))
        text[strInd] = new_line
    
        