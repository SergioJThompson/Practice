from tkinter import *
from tkinter import font
from tkinter import filedialog
from tkinter import Event

from os.path import expanduser

from simpleaudio import WaveObject

from Playbutton import Playbutton
from pydub import AudioSegment

import math


def create_root_window():
    root = Tk()
    window_width = 302
    window_height = 50
    root.minsize(window_width, window_height)
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()
    x_coord = (screen_width/2) - (window_width/2)
    y_coord = (screen_height/2) - (window_height/2)
    root.geometry("%dx%d+%d+%d" % (window_width, window_height, x_coord, y_coord))
    root.title("Sonic Surge")

    play_btn = Playbutton(root, text="Play mp3")
    choose_btn = Button(root, text="Choose mp3", command=lambda: change_file(play_btn, file_loaded_lbl))

    file_loaded_lbl = Label(root, text="No file loaded.", justify=CENTER)
    invis_lbl1 = Label(root)
    invis_lbl2 = Label(root, width=10)

    file_loaded_lbl.grid(column=0, row=0, columnspan=3)
    invis_lbl1.grid(column=0, row=1, columnspan=3)

    play_btn.grid(column=0, row=2)
    invis_lbl2.grid(column=1, row=2)
    choose_btn.grid(column=2, row=2)

    root.grid_columnconfigure(1, weight=1)
    root.grid_rowconfigure(1, weight=1)

    root.bind("<Configure>", lambda event: resize_text(event, file_loaded_lbl))

    # TODO: make label text change responsively when window size increased/decreased


def file_loaded_msg_first_part():
    return "File loaded: "


def get_truncatable_part(txt):
    if file_loaded_msg_first_part() in txt:
        return txt[len(file_loaded_msg_first_part()):]
    else:
        return txt


def resize_text(event, lbl):
    txt = lbl.cget("text")
    truncatable_part = get_truncatable_part(lbl.cget("text"))
    txt_font = font.nametofont(lbl.cget("font"))
    # window = lbl.master
    while not text_would_fit_in_window(txt, txt_font, event):
        truncated = truncate(truncatable_part)
        txt = txt.replace(truncatable_part, truncated)
    lbl.config(text=txt)


def change_file(play_btn, file_loaded_lbl):
    play_btn.stop()
    path = get_file_path_from_user()
    if path != '':
        play_btn.set_sound(get_wave_object(path))
        file_name = get_file_name_from_path(path)
        file_loaded_lbl.config(text=file_loaded_msg(file_name, file_loaded_lbl))


def get_file_path_from_user():
    return filedialog.askopenfilename(initialdir=expanduser("~/Music/"), filetypes=[("MP3 files", "*.mp3")])


def file_loaded_msg(file_name, lbl):
    txt = file_loaded_msg_first_part() + file_name
    txt_font = font.nametofont(lbl.cget("font"))
    window = lbl.master
    while not text_would_fit_in_window(txt, txt_font, window):
        file_name = truncate(file_name)
        txt = file_loaded_msg_first_part() + file_name
    return txt


def get_file_name_from_path(path):
    return path[path.rfind("/")+1:]


def text_would_fit_in_window(txt, txt_font, window):
    text_width = txt_font.measure(txt)
    window_width = window.winfo_width()
    return text_width + 2 < window_width


def truncate(s):
    halves = halve(s)
    dots = " ... "
    half_dots_len = math.ceil(len(dots)/2.0)
    return halves[0][:-half_dots_len] + dots + halves[1][half_dots_len:]
    # TODO: if filename is truncated, make it responsively less truncated as user increases window size


def halve(s):
    i = len(s)
    if i % 2 == 0:
        return s[0:i//2], s[i//2:]
    return s[0:(i//2+1)], s[(i//2+1):]


def get_wave_object(audio_file_path):
    seg = AudioSegment.from_file(audio_file_path)
    return WaveObject(seg.raw_data, seg.channels, seg.sample_width, seg.frame_rate)


def main():
    create_root_window()
    mainloop()


main()

# TODO: pause button
# TODO: backwards audio button!
