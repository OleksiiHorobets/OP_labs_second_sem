from fileManip import*

def main():
    input_file_name = 'inputData.txt'
    output_file_name = 'outputData.txt'
    text = get_input_data(input_file_name)
    display_text('\n------Initial text------',text)
    write_to_file(text, input_file_name)
    display_data('\n----Input file content-------', input_file_name)
    
    sort_text(text)
    
    display_text('\n------Sorted text------',text)
    add_len(text)
    
    display_text('\n------Added length of rows in text------',text)
    
    write_to_file(text, output_file_name)
    
main()