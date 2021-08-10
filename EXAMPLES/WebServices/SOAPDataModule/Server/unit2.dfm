object BiolifeService: TBiolifeService
  OldCreateOrder = False
  Left = 194
  Top = 107
  Height = 150
  Width = 215
  object DataSetProvider1: TDataSetProvider
    DataSet = ClientDataSet1
    Constraints = True
    Left = 16
    Top = 24
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    FileName = 
      'C:\WPGDemos_bcb\examples\c\WebServices\SOAPDataModule\Server\bio' +
      'life.xml'
    Params = <>
    Left = 96
    Top = 24
  end
end
