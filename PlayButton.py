from tkinter import Button
from pydub.playback import play
# import simpleaudio


class PlayButton(Button):

    def __init__(self, sound, *args, **kwargs):
        self.sound = sound
        super().__init__(*args, command=self.play, **kwargs)

    def play(self):
        play(self.sound)

    # TODO: Make the program use pydub instead of pygame.
