# TODO: Set action label text to "" when file loaded. Or maybe "File loaded!"

from pydub import AudioSegment
from tkinter import filedialog
from os.path import expanduser

from SoundBuilder import SoundBuilder
from TextEditor import TextEditor
from MsgLibrary import MsgLibrary as Msgs
from Tags import Tags


class Operator:

    @staticmethod
    def stop_playback_and_load_file_and_update_labels(bank, player, loaded_lbl, reversed_file_lbl):
        player.stop_if_playing()

        path = filedialog.askopenfilename(initialdir=expanduser("~/Music/"), filetypes=[("MP3 files", "*.mp3")])
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
    def stop_playback_and_lower_frames_and_update_label(bank, player, action_lbl):
        player.stop_if_playing()

        if bank.has_sound_with_exact_tags({Tags.FRAMES_LOWERED}):
            lowered_sound = bank.get_sound_with_exact_tags({Tags.FRAMES_LOWERED})
            original_sound = bank.get_sound_with_exact_tags({})
            if player.sound == lowered_sound:
                player.sound = original_sound
                action_lbl.config(text="Raised sample rate back to normal!")
            elif player.sound == original_sound:
                player.sound = lowered_sound
                action_lbl.config(text="Lowered sample rate!")
        elif bank.has_sound_with_exact_tags({}):
            seg = AudioSegment.from_file(bank.get_sound_with_exact_tags({}))    # TODO: get file
            lowered_seg = seg.set_frame_rate(int (seg.frame_rate / 4))
            # TODO: Get the lowest sample rate that'll work and use that.
            lowered_sound = SoundBuilder.build_sound_from_audio_seg(lowered_seg)
            lowered_sound.path = player.sound.path
            bank.add(lowered_seg)
            player.sound = lowered_sound
            action_lbl.config(text="Lowered sample rate!")
        else:
            action_lbl.config(text="No file to modify!")

    @staticmethod
    def stop_playback_and_reverse_file_and_update_label(bank, player, action_lbl):
        player.stop_if_playing()
        if bank.has_sound_with_exact_tags({Tags.REVERSED}):
            reversed_sound = bank.get_sound_with_exact_tags({Tags.REVERSED})
            original_sound = bank.get_sound_with_exact_tags({})
            if player.sound == reversed_sound:
                player.sound = original_sound
                action_lbl.config(text="Unreversed file!")
            elif player.sound == original_sound:
                player.sound = sounds[Tags.REVERSED]
                action_lbl.config(text="Reversed file!")
        elif bank.has_sound_with_exact_tags({}):
            seg = AudioSegment.from_file(bank.get_sound_with_exact_tags({}))    # TODO: get file
            reversed_seg = AudioSegment.from_file(player.sound.path).reverse()
            reversed_sound = SoundBuilder.build_sound_from_audio_seg(reversed_seg)
            bank.add(Tags.REVERSED, reversed_sound)
            player.sound = reversed_sound
            action_lbl.config(text="Reversed file!")
        else:
            action_lbl.config(text="No file to reverse!")

    # TODO: Combining reverse and lower_frames loading actions into one
    # TODO: Consider what to do in the case a de-modification of a file with multiple tags, i.e. one tag being removed

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
