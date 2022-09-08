import keyboard
# import pyautogui

# text_to_print='default_predefined_text'
# shortcut = 'x' #define your hot-key
# print('Hotkey set as:', shortcut)

# def on_triggered(): #define your function to be executed on hot-key press
#     while keyboard.is_pressed('y')
#     	keyboard.press('y')
#     keyboard.release('y')
#     #write_to_textfield(text_to_print) #<-- your function
# keyboard.add_hotkey(shortcut, on_triggered) #<-- attach the function to hot-key

# print("Press ESC to stop.")
# keyboard.wait('esc')



keyboard.remap_key('a', 'n+y+i+p')
keyboard.remap_key('l', 'n+y+9+p')

keyboard.wait('esc')