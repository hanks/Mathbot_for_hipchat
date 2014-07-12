#!/usr/bin/env python
# -*- coding: utf-8 -*-

from errbot import botcmd
from errbot import BotPlugin
import logging

from swig_src.four_rubes import calculate as cal

class MathBot(BotPlugin):
    """Simple four operation rubes bot
    """

    # define err library version needed for plugin
    min_err_version = '2.0.0'
    max_err_version = '2.0.0'

    @botcmd
    def calculate(self, msg, args):
        """Evaluate string and return value
        """
        # need to be encoded to str to be used as std::string type in C++
        eval_str = str(args.strip())

        logging.info('eval {}'.format(eval_str))
        
        try:
            result = cal(eval_str)
        except ValueError as e:
            logging.exception('Evaluate string error.')
            result = str(e)

        return result
        
        
        
