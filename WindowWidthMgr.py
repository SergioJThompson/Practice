class WindowWidthMgr:

    def __init__(self, width):
        self.width = width

    def window_width_changed(self, new_width):
        return new_width != self.width

    def set_width(self, width):
        self.width = width
