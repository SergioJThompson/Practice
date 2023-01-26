from tkinter import Button
from simpleaudio import WaveObject
import time


class Playbutton(Button):

    def __init__(self, *args, wave_obj=None, **kwargs):
        if wave_obj and type(wave_obj) is not WaveObject:
            raise ValueError("Object not of type WaveObject passed to PlayButton as wave_obj")

        self.wave_obj = wave_obj
        self.play_obj = None
        self.time_last_playback_started = None
        self.time_spent_playing_back_file = None

        super().__init__(*args, command=self.play, **kwargs)

    def set_sound(self, wave_obj):
        self.wave_obj = wave_obj

    def play(self):
        self.stop()
        if self.wave_obj:
            if self.time_spent_playing_back_file:
                self.modify_wave_obj_to_start_where_it_was_stopped()
            self.play_obj = self.wave_obj.play()
            self.time_last_playback_started = time.time()

    def stop(self):
        if self.is_playing():
            self.play_obj.stop()

    def is_playing(self):
        return self.play_obj and self.play_obj.is_playing()

    def pause(self):
        if self.is_playing():
            self.play_obj.stop()
            self.time_spent_playing_back_file = time.time() - self.time_last_playback_started

    def modify_wave_obj_to_start_where_it_was_stopped(self):
        if self.play_obj:
            self.wave_obj = self.wave_obj[self.time_spent_playing_back_file * 1000:]

    # TODO: Change all this to use pydub so you can pause and resume. Damn it
