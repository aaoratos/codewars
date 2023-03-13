SEC_IN_MIN = 60
SEC_IN_HOUR = SEC_IN_MIN * 60
SEC_IN_DAY = SEC_IN_HOUR * 24
SEC_IN_YEAR = SEC_IN_DAY * 365


def parse_seconds(sec: int) -> dict:
    td = dict()
    td['year'] = sec // SEC_IN_YEAR
    sec %= SEC_IN_YEAR
    td['day'] = sec // SEC_IN_DAY
    sec %= SEC_IN_DAY
    td['hour'] = sec // SEC_IN_HOUR
    sec %= SEC_IN_HOUR
    td['minute'] = sec // SEC_IN_MIN
    sec %= SEC_IN_MIN
    td['second'] = sec
    return {key: val for key, val in td.items() if val > 0}


def format_duration(sec: int):
    if sec == 0:
        return 'now'
    fmt_str = ''
    time_dikt = parse_seconds(sec)
    plural = (lambda n, s: s if n == 1 else s + 's')
    if len(time_dikt) == 1:
        fmt_str = '{} {}'.format(list(time_dikt.values())[0],
                                 plural(list(time_dikt.values())[0],
                                        list(time_dikt.keys())[0]))
        return fmt_str
    for key, val in time_dikt.items():
        if key == list(time_dikt.keys())[-2]:
            fmt_str += '{} {} and '.format(val, plural(val, key))
        else:
            fmt_str += '{} {}, '.format(val, plural(val, key))
    return fmt_str[0:-2]
