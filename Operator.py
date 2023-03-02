# TODO: Set action label text to "" when file loaded. Or maybe "File loaded!"

from tkinter import filedialog
from os.path import expanduser

from SoundBuilder import SoundBuilder
from TextEditor import TextEditor
from MsgLibrary import MsgLibrary as Msgs, MsgLibrary
from Tags import Tags


class Operator:

    @staticmethod
    def pause_if_playing(player):
        player.pause_if_playing()

    @staticmethod
    def do_operation(bank, sound, tag):
        if tag == Tags.REVERSED:
            return Operator.get_reverse(bank, sound)
        if tag == Tags.FRAMES_LOWERED:
            return Operator.get_altered_sample_rate(bank, sound)

    @staticmethod
    def get_reverse(bank, sound):
        reversed_tags = set(sound)
        SoundBuilder.add_or_remove(Tags.REVERSED, reversed_tags)

        if bank.has_sound_with_exact_tags(reversed_tags):
            sound = bank.get_sound_with_exact_tags(reversed_tags)
        else:
            reversed_sound = SoundBuilder.build_reversed(player.sound)
            bank.add(reversed_sound)
            sound = reversed_sound
        return sound

    @staticmethod
    def get_altered_sample_rate(bank, sound):
        altered_tags = set(sound)
        SoundBuilder.add_or_remove(Tags.FRAMES_LOWERED, altered_tags)

        if bank.has_sound_with_exact_tags(altered_tags):
            sound = bank.get_sound_with_exact_tags(altered_tags)
        else:
            if Tags.FRAMES_LOWERED in altered_tags:
                new_sample_rate = 800
                altered_sound = SoundBuilder.build_new_sound_with_altered_sample_rate(player.sound, new_sample_rate)
            else:
                sound_to_alter = bank.get_sound_with_exact_tags(set())
                for tag in altered_tags:
                    sound_to_alter = Operator.do_operation(bank, sound_to_alter, tag)
                altered_sound = sound_to_alter
            bank.add(altered_sound)
            return altered_sound

    @staticmethod
    def stop_playback_and_load_file_and_update_labels(bank, player, loaded_lbl, reversed_file_lbl):
        player.stop_if_playing()

        path = filedialog.askopenfilename(initialdir=expanduser("/Users/sergiojthompson/Documents/programs/sonic-surge/test_files"), filetypes=[("MP3 files", "*.mp3")])
        # TODO: Change that directory to ~/Music/ when program is finished
        if path:  # If user didn't click cancel
            sound = SoundBuilder.build_sound_from_path(path)
            bank.clear()
            bank.add(sound)
            player.sound = sound

            file_name = TextEditor.get_file_name_from_path(path)
            fit_name = TextEditor.write_file_loaded_msg(file_name, loaded_lbl)
            loaded_lbl.config(text=fit_name)
            reversed_file_lbl.config(text="File loaded!")

    @staticmethod
    def stop_playback_and_change_sound_and_update_label(bank, player, tag, action_lbl):
        if not player.sound:
            action_lbl.config(text=MsgLibrary.no_file_to_alter(tag))
            return
        player.stop_if_playing()
        Operator.do_operation(bank, player, tag)
        action_lbl.config(text=MsgLibrary.altered_file(tag))

    # TODO: Build from original instead of working backwards from mod if sample rate lowered

    @staticmethod
    def stop_playback_and_update_label(player, lbl):
        if player.is_playing():
            player.stop()
            lbl.config(text=Msgs.stopped_playback())
        else:
            lbl.config(text=Msgs.no_playback_to_stop())

    @staticmethod
    def try_to_play_and_update_lbl(player, lbl):
        if player.sound:
            player.play()
            lbl.config(text=Msgs.playing())
        else:
            lbl.config(text=Msgs.no_file_to_play())
        # TODO: Say "Finished playing" when file finishes playing
