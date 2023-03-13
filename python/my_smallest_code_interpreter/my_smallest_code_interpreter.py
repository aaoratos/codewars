TAPE_SIZE = 4096
OUTPUT_BUFFER_SIZE = 4096


def build_jump_table(code):
    brace_stack = []
    jump_table = {}
    for i, cmd in enumerate(code):
        if cmd == '[':
            brace_stack.append(i)
        elif cmd == ']':
            left = brace_stack.pop()
            jump_table[left] = i
            jump_table[i] = left
    return jump_table


def brain_luck(code, program_input):
    tape = [0] * TAPE_SIZE
    output_buf = ''
    tape_index = 0
    input_index = 0
    code_index = 0
    jump_table = build_jump_table(code)
    while code_index < len(code):
        match code[code_index]:
            case '>':
                tape_index += 1
            case '<':
                tape_index -= 1
            case '+':
                tape[tape_index] = (tape[tape_index] + 1) % 256
            case '-':
                tape[tape_index] = (tape[tape_index] - 1) % 256
            case '.':
                output_buf += chr(tape[tape_index])
            case ',':
                tape[tape_index] = ord(program_input[input_index])
                input_index += 1
            case '[':
                if tape[tape_index] == 0:
                    code_index = jump_table[code_index]
            case ']':
                if tape[tape_index] != 0:
                    code_index = jump_table[code_index]
        code_index += 1
    return output_buf
