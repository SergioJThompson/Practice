import tkinter.messagebox


def create_window(msg):
    tkinter.messagebox.showinfo("Message", msg)


if __name__ == '__main__':
    create_window('Help')
