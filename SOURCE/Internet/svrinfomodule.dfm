object WebModule2: TWebModule2
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'WebActionItem1'
      PathInfo = '/List'
      Producer = PageProducerSelect
    end
    item
      Name = 'WebActionItem2'
      PathInfo = '/Clean'
      OnAction = CleanAction
    end
    item
      Name = 'WebActionItem3'
      PathInfo = '/Details'
      Producer = PageProducerDetails
    end>
  Left = 213
  Top = 135
  Height = 191
  Width = 198
  object PageProducerSelect: TPageProducer
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEADING>'
      '<TITLE>Registered Server Details</TITLE>'
      '</HEADING>'
      '<BODY onLoad="init()" >'
      '<SCRIPT TYPE="text/javascript">'
      '<!--'
      '  var LastProgID = '#39'LastProgID'#39';'
      ''
      '  var URLPath = "/"'
      '  function Go(s)'
      '  {'
      '    // Save the progid in a cookie'
      '    var exp = new Date();'
      '    exp.setTime(exp.getTime() + (7 * 24 * 60 * 60 * 1000));'
      '    document.cookie = LastProgID + '#39'='#39' + s +'
      '    '#39'; expires='#39' + exp.toGMTString();'
      '    // jump using the progid'
      '    window.location.href = URLPath + s;'
      '  }'
      ''
      '  function GetCookie(sName)'
      '  {'
      '    var aCookie = document.cookie.split("; ");'
      '    for (var i=0; i <aCookie.length; i++)'
      '    {'
      '      var aCrumb = aCookie[i].split("=");'
      '      if (sName == aCrumb[0])'
      '        return unescape(aCrumb[1]);'
      '    }'
      '    return null;'
      '  }'
      ''
      '  function init()'
      '  {'
      '    var s = GetCookie(LastProgID);'
      '    if (s != null)'
      '      document.F.S.value = s;'
      '  }'
      '// -->'
      '</script>'
      '<h2>Registered Servers</h2>'
      
        '<a>View List</a>&nbsp;|&nbsp;<a HREF="<#PATH>Details">View Detai' +
        'ls</a>'
      '<#LIST>'
      '</BODY>'
      '</HTML>'
      ' '
      ' '
      ' ')
    OnHTMLTag = ServerListPageHTMLTag
    Left = 56
    Top = 16
  end
  object PageProducerDetails: TPageProducer
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEADING>'
      '<TITLE>Registered Server Details</TITLE>'
      '</HEADING>'
      '<h2>Registered Servers</h2>'
      
        '<a HREF=<#PATH>List>View List</a>&nbsp;|&nbsp;<a>View Details</a' +
        '>'
      '<#DETAILS>'
      '</BODY>'
      '</HTML>'
      ' ')
    OnHTMLTag = ServerListPageHTMLTag
    Left = 96
    Top = 80
  end
end
