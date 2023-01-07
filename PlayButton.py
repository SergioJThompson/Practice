from tkinter import Button
from pygame import mixer


class PlayButton(Button):

    def __init__(self, sound, *args, **kwargs):
        self.sound = sound
        super().__init__(*args, command=self.play, **kwargs)

    def play(self):
        sound = mixer.Sound(self.sound)
        channel = mixer.Channel(0)
        channel.play(sound, maxtime=1000)  # Play the first second of the sound file
        channel.queue(sound)  # Queue up the rest of the sound file to be played after the first second has elapsed
