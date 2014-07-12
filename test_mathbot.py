import unittest
import os
from errbot.backends.test import FullStackTest, pushMessage, popMessage
from errbot import plugin_manager

class MathBotTests(FullStackTest):
    """Test suite for math bot
    """

    def setUp(self):
        me = os.path.dirname(os.path.realpath(os.path.abspath(__file__)))
        # Adding /la/bla to path is needed because of the path mangling
        # FullStackTest does on extra_test_file.
        plugin_dir = os.path.join(me, 'la', 'bla')
        super(MathBotTests, self).setUp(extra_test_file=plugin_dir)
        self.plugin = plugin_manager.get_plugin_obj_by_name('MathBot')

    def test_calculate(self):
        """Test calculate command
        """
        pushMessage('!calculate 1+2')
        self.assertEqual(popMessage(), '3')
        
        pushMessage('!calculate 1+2*(5-1)')
        self.assertEqual(popMessage(), '9')

    def test_calculate_with_exception(self):
        """Test calculate command with exception
        """
        pushMessage('!calculate 1+2)')
        self.assertEqual(popMessage(), 'Input is error!')

if __name__ == '__main__':
    unittest.main()
